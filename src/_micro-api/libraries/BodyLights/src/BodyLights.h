// BodyLights.h

#ifndef _BODYLIGHTS_h
#define _BODYLIGHTS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>
class BodyLights {
public:
	BodyLights(int pin);
	void setTimeDelay(long timeDelay);
	void setColor(int r, int g, int b);
	void setColor(int r, int g, int b, int w);
	void setBrightness(int brightness);
	void fadeInAndOut();
	void fadeInAndOut(int minBrightness, int maxBrightness);
private:
	int _pin;
	long _timeDelay;
	int _r;
	int _g;
	int _b;
	int _w;
	int _brightness;
	bool _increase;
	long _lastRunTime;
	int _stepAmount;
	void _updateColors();
};
#endif

