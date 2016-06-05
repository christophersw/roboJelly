// 
// 
// 

#include "ArmLights.h"

ArmLights::ArmLights(int redPin, int greenPin, int bluePin)
{
	_redPin = redPin;
	_bluePin = bluePin;
	_greenPin = greenPin;

	pinMode(_redPin, OUTPUT);
	pinMode(_greenPin, OUTPUT);
	pinMode(_bluePin, OUTPUT);

	_lastRunTime = millis();
	_timeDelay = 10;
	_stepAmount = 1;
}

void ArmLights::setColor(int r, int g, int b)
{
	r = 255 - r;
	g = 255 - g;
	b = 255 - b;
	analogWrite(_redPin, r);
	analogWrite(_greenPin, g);
	analogWrite(_bluePin, b);
}

void ArmLights::fadeInAndOut(int minBrightness, int maxBrightness)
{
	//If more time than min delay has expired, run
	if (millis() > (_lastRunTime + _timeDelay)) {
		if (_r > 255 - _stepAmount ||
			_g > 255 - _stepAmount || 
			_b > 255 - _stepAmount) {
			_increase = false;
		}

		if (_r < _stepAmount ||
			_g < _stepAmount ||
			_b < _stepAmount) {
			_increase = true;
		}

		//Move up
		if (_increase) {
			_r += _stepAmount;
			_g += _stepAmount;
			_b += _stepAmount;
		}
		else {
			_r -= _stepAmount;
			_g -= _stepAmount;
			_b -= _stepAmount;
		}

		setColor(_r, _g, _b);
		_lastRunTime = millis();

		return;
	}

	return;
}
