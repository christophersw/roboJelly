#include <known_16bit_timers.h>
#include <Adafruit_TiCoServo.h>
#include "BodyLights.h"
#include "SwimServo.h"
#include <QueueList.h>

#define LED_PIN 3


QueueList<byte> queue;
SwimServo swimServo = SwimServo(9, 100);
BodyLights bodyLights = BodyLights(LED_PIN);

bool bodyLightFade = true;
bool swim = true;

void setup() {
	bodyLights.setColor(random(75, 255), random(86, 255), random(99, 255), 255);
	bodyLights.setTimeDelay(50);

	queue.push(1);
	queue.push(2);
}

void loop() {
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
			if (swim == true) {
				swimServo.Swim(10, 5);
				queue.push(1);
			}
			break;
			
		// Jelly Body Light Fade in and Out
		case 2:
			if (bodyLightFade == true) {
				bodyLights.fadeInAndOut();
				queue.push(2);
			}
			break;
		default:
			break;
	}
}
