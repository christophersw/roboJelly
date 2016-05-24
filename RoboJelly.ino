#include <known_16bit_timers.h>
#include <Adafruit_TiCoServo.h>
#include "BodyLights.h"
#include "SwimServo.h"
#include <QueueList.h>

#define LED_PIN 3
const byte SWIM_STOP_SWITCH_PIN = 2;

QueueList<byte> queue;
SwimServo swimServo = SwimServo(9, 50);
BodyLights bodyLights = BodyLights(LED_PIN);

//variables to keep track of the timing of recent interrupts
unsigned long button_time = 0;
unsigned long last_button_time = 0;

byte bodyLightFade = HIGH;
volatile byte swim = HIGH;

void setup() {
	Serial.begin(9600);
	Serial.println("Initializing");

	attachInterrupt(0, swimSwitch, FALLING);

	randomSeed(1239098091237234);
	bodyLights.setColor(random(30, 35), random(240, 255), random(80, 85), 255);
	bodyLights.setTimeDelay(50);
	queue.push(1);
	queue.push(2);
}

void loop() {
	digitalWrite(13, LOW);
	delay(10); //pretend to be doing something useful
	runNext();
}

void runNext() {
	if (queue.isEmpty()) {
		return;
	}

	byte next = queue.pop();

	switch (next) {
		// Jelly Swim
		case 1:
			if (swim == HIGH) {
				swimServo.Reverse();
				swim = LOW;
			}

			swimServo.Swim(20, 65);
			queue.push(1);

			break;
			
		// Jelly Body Light Fade in and Out
		case 2:
			if (bodyLightFade == HIGH) {
				bodyLights.fadeInAndOut();
				queue.push(2);
			}
			break;
		default:
			break;
	}
}

void swimSwitch() {
	button_time = millis();
	//check to see if increment() was called in the last 250 milliseconds
	if (button_time - last_button_time > 250)
	{
		swim = HIGH;
		digitalWrite(13, HIGH);
		last_button_time = button_time;
	}
}