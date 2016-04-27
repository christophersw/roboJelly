// SwimServo.h

#ifndef _SWIMSERVO_h
#define _SWIMSERVO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include <Servo.h>
#else
	#include "WProgram.h"
#endif

class SwimServo {
public:
	SwimServo(int pin);
	SwimServo(int pin, int minAngle, int maxAngle, int timeDelay, int stepAmount);
	void Swim();

private:
	int _servoPin;
	Servo _servo;
	int _minAngle;
	int _maxAngle;
	int _timeDelay;
	int _stepAmount;
	int _currentPos;
	bool _increase;
	long _lastRunTime;
};

#endif

