// armLights.h

#ifndef _ARMLIGHTS_h
#define _ARMLIGHTS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class ArmLights
{
 protected:
	 int _r;
	 int _g; 
	 int _b;
	 int _redPin;
	 int _greenPin;
	 int _bluePin;
	 long _lastRunTime;
	 long _timeDelay;
	 int _brightness;
	 int _stepAmount;
	 bool _increase;
 public:
	ArmLights(int redPin, int greenPin, int bluePin);
	void setColor(int r, int g, int b);
	void fadeInAndOut(int minBrightness, int maxBrightness);
};

#endif

