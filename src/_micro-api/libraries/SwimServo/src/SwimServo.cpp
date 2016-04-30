/*
SwimServo.cpp - Library to control jelly swim servo
Created by Christopher Webster 26 April 2016
Released into the public domain.
*/

#include "Arduino.h"
#include "SwimServo.h"
#include "Servo.h"


/**
* Swim Servo Constructor
* Sets class defaults...
*/
SwimServo::SwimServo(int pin) {
	_servoPin = pin;
	_minAngle = 90;
	_maxAngle = 210;
	_timeDelay = 100;
	_stepAmount = 5;
	_currentPos = 90;
	_lastRunTime = millis();
}

/**
* Swim Servo Constructor
* @param	pin			Pin the servo is attache to
* @param	minAngle	The minimum allowable servo angle
* @param	maxAngle    The maxinmum allowable servo angle
* @param	timeDelay   Total sweep time target (fastest allowed)
* @param	stepAmount  Amount of each step action
*/
SwimServo::SwimServo(int pin, int minAngle, int maxAngle, long timeDelay, int stepAmount)
{
	_servoPin = pin;
	_minAngle = minAngle;
	_maxAngle = maxAngle;
	_timeDelay = timeDelay;
	_stepAmount = stepAmount;
	_currentPos = 90;
	_lastRunTime = millis();
};

/**
* Swim!
*/

void SwimServo::Swim() {
	static Servo servo = Servo();
	servo.attach(_servoPin);

	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {

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
		servo.write(_currentPos);
		
		return;
	}

	return;
};

void SwimServo::SwimRandom(int minStep, int maxStep) {
	static Servo servo = Servo();
	servo.attach(_servoPin);
	
	int randStepAmount = random(minStep, maxStep);

	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {

		if (_currentPos >= _maxAngle) {
			_increase = false;
		}

		if (_currentPos <= _minAngle) {
			_increase = true;
		}

		//Move up
		if (_increase) {
			_currentPos += randStepAmount;
		}
		else {
			_currentPos -= randStepAmount;
		}

		_lastRunTime = millis();
		servo.write(_currentPos);

		return;
	}

	return;
};