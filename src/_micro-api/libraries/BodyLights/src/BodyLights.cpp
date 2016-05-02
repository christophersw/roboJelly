/*
*BodyLights.cpp = Library to control jelly's body lights
* Created by Christopher Webster 26 April 2016
* Released into the public domain.
*/
#include "BodyLights.h"
#include <Adafruit_NeoPixel.h>

static Adafruit_NeoPixel  _strip = Adafruit_NeoPixel(60, 3, NEO_RGBW + NEO_KHZ800);

BodyLights::BodyLights(int pin)
{
	_pin = pin;
	_lastRunTime = millis();
	_r = 255;
	_g = 255;
	_b = 255;
	_w = 255;
	_timeDelay = 10;
	_stepAmount = 1;
	_strip.begin();
}

void BodyLights::setTimeDelay(long timeDelay)
{
	_timeDelay = timeDelay;
	_lastRunTime = millis();
}

void BodyLights::setColor(int r, int g, int b)
{
	_r = r;
	_g = g;
	_b = b;
}

void BodyLights::setColor(int r, int g, int b, int w)
{
	_r = r;
	_g = g;
	_b = b;
	_w = w;
}

void BodyLights::setBrightness(int brightness)
{
	_brightness = brightness;
}

void  BodyLights::fadeInAndOut() {
	fadeInAndOut(0, 255);
};

void BodyLights::fadeInAndOut(int minBrightness, int maxBrightness)
{	
	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {
		if (_brightness >= maxBrightness - _stepAmount) {
			_increase = false;
		}

		if (_brightness <= minBrightness + _stepAmount) {
			_increase = true;
		}

		//Move up
		if (_increase) {
			_brightness += _stepAmount;
		}
		else {
			_brightness -= _stepAmount;
		}

		_strip.Color(_r, _g, _b, _w);
		_strip.setBrightness(_brightness);

		_updateColors();
		_strip.show();

		return;
	}

	return;
}

void BodyLights::_updateColors()
{
	for (int x = 0; x<_strip.numPixels(); x++) {
		_strip.setPixelColor(x, _r, _g, _b);
	}
}
