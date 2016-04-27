#include "SwimServo.h"
#include <QueueList.h>
#include <Servo.h>

#define LED_PIN 2
#define SERVO_PIN 7

QueueList<byte> queue;
SwimServo swimServo = SwimServo(7, 90, 210, 100, 5);

void setup() {
	queue.push(1);
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
		swimServo.Swim();
		queue.push(1);
		return;
	}
}