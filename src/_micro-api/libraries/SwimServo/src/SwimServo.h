// SwimServo.h

#ifndef _SWIMSERVO_h
#define _SWIMSERVO_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


class SwimServo {
public:
	SwimServo(int pin, long timeDelay);
	void Swim(int speed, int amount);
	void Reverse();

private:
	int _servoPin;
	long _timeDelay;
	long _lastRunTime;
	bool _direction;
};

#endif

