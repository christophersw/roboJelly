/*
SwimServo.cpp - Library to control jelly swim servo
Created by Christopher Webster 26 April 2016
Released into the public domain.
*/

#include "Arduino.h"
#include "SwimServo.h"
#include <Adafruit_TiCoServo.h>


/**
* Swim Servo Constructor
* @param	pin			Pin the servo is attache to
* @param	timeDelay   Check Every time target (fastest allowed)
*/
SwimServo::SwimServo(int pin, long timeDelay)
{
	_servoPin = pin;
	_timeDelay = timeDelay;
	_lastRunTime = millis();
};

/**
* Swim!
*/

void SwimServo::Swim(int speed, int amount) {
	static Adafruit_TiCoServo servo;
	static int max = amount;
	static bool increasing = true;
	
	if (!servo.attached())
	{
		servo.attach(_servoPin);
	}
	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {

		Serial.println(max);

		if (increasing) {
			max++;

			if (max > amount) {
				Serial.print("increasing: ");
				Serial.println(max);
				increasing = false;
				servo.write(90 - speed * 1.1);
			}
		}
		else {
			max--;

			if (max <= 1) {
				Serial.print("decreasing: ");
				Serial.println(max);
				increasing = true;
				servo.write(90 + speed);
			}
		}

		_lastRunTime = millis();
	}
};
