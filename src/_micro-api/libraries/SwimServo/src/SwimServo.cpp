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
* @param	pin			Pin the servo is attached to
* @param	timeDelay   Check Every time target (fastest allowed)
*/
SwimServo::SwimServo(int pin, long timeDelay)
{
	_servoPin = pin;
	_timeDelay = timeDelay;
	_lastRunTime = millis();
	_direction = false;
};

/**
* Swim!
*/

void SwimServo::Swim(int speed, int amount) {
	static Adafruit_TiCoServo servo;
	static int max = amount;
	
	if (!servo.attached())
	{
		servo.attach(_servoPin);
	}
	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {
		if(_direction){
			servo.write(90 - speed);
		}
		else {
			servo.write(90 + speed);
		}
		_lastRunTime = millis();
	}
};

void SwimServo::Reverse() {
	_direction = !_direction;
	_lastRunTime = 9999; // queue this for immediate action
}