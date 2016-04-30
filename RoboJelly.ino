#include "SwimServo.h"
#include <QueueList.h>
#include <Servo.h>

#define LED_PIN 2
#define SERVO_PIN 7

QueueList<byte> queue;
SwimServo swimServo = SwimServo(7, 90, 210, 70, 5);
int i = 0;

void setup() {
	queue.push(1);
	pinMode(13, OUTPUT);
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
		case 1:
			swimServo.SwimRandom(1, 15);
			queue.push(1);
			break;
		default:
			break;
	}
}