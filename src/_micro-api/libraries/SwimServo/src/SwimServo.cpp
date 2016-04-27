/*
SwimServo.cpp - Library to control jelly swim servo
Created by Christopher Webster 26 April 2016
Released into the public domain.
*/

#include "Arduino.h"
#include "SwimServo.h"

/**
* Swim Servo Constructor
* Sets class defaults...
*/
SwimServo::SwimServo(int pin) {
	_servoPin = pin;
	_servo.attach(_servoPin);
	_minAngle = 90;
	_maxAngle = 210;
	_timeDelay = 100;
	_stepAmount = 5;
	_currentPos = 90;
}

/**
* Swim Servo Constructor
* @param	pin			Pin the servo is attache to
* @param	minAngle	The minimum allowable servo angle
* @param	maxAngle    The maxinmum allowable servo angle
* @param	timeDelay   Total sweep time target (fastest allowed)
* @param	stepAmount  Amount of each step action
*/
SwimServo::SwimServo(int pin, int minAngle, int maxAngle, int timeDelay, int stepAmount)
{
	_servoPin = pin;
	_servo.attach(_servoPin);
	_minAngle = minAngle;
	_maxAngle = maxAngle;
	_timeDelay = timeDelay;
	_stepAmount = stepAmount;
	_currentPos = 90;
};

/**
* Swim!
*/

void SwimServo::Swim() {
	//If more time than min delay has expired, run
	if (millis() > _lastRunTime + (_timeDelay / _stepAmount)) {

		if (_currentPos >= _maxAngle) {
			_increase = false;
		}

		if (_currentPos <= _minAngle) {
			_increase = true;
		}

		//Move up
		if (_increase) {
			_currentPos += _stepAmount;
		}
		else {
			_currentPos -= _stepAmount;
		}

		_lastRunTime = millis();
		_servo.write(_currentPos);
		return;
	}
	else
	{
		return;
	}
};