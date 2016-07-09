#include <known_16bit_timers.h>
#include <Adafruit_TiCoServo.h>
#include "BodyLights.h"
#include "SwimServo.h"
#include "ArmLights.h"
#include <QueueList.h>


QueueList<byte> queue;
SwimServo swimServo = SwimServo(9, 50);
BodyLights bodyLights = BodyLights(3);
ArmLights armLights = ArmLights(11, 10, 9);

//variables to keep track of the timing of recent interrupts
volatile unsigned long button_time = 0;
volatile unsigned long last_button_time = millis();

byte bodyLightFade = HIGH;
volatile byte swim = HIGH;

void setup() {
	Serial.begin(9600);
	Serial.println("Initializing");

	attachInterrupt(0, swimSwitch, RISING);

	randomSeed(1091237234);
	bodyLights.setTimeDelay(50);
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
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
		case 3:
			//armLights.fadeInAndOut(0, 255);
			queue.push(3);
			break;
		case 4:
			randoColors();
			queue.push(4);
			break;
		default:
			break;
	}
}

void randoColors() {
	static int x = 0; 

	if (x == 0) {
		int r = random(0, 255);
		int g = random(0, 255);
		int b = random(0, 255);

		bodyLights.setColor(r, g, b);
		armLights.setColor(r, g, b);
		x = 1000;
	}
	else {
		x--;
	}
}

void swimSwitch() {
	Serial.println(button_time - last_button_time);
	button_time = millis();
	//check to see if swimSwitch() was called in the last 250 milliseconds
	if (button_time - last_button_time > 1000)
	{
		Serial.println("running");
		swim = HIGH;
		digitalWrite(13, HIGH);
		last_button_time = button_time;
	}
}