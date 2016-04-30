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
	SwimServo(int pin, int minAngle, int maxAngle, long timeDelay, int stepAmount);
	void Swim();

private:
	int _servoPin;
	int _minAngle;
	int _maxAngle;
	long _timeDelay;
	int _stepAmount;
	int _currentPos;
	bool _increase;
	long _lastRunTime;
};

#endif

