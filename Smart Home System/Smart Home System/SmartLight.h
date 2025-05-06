#pragma once
#include "Device.h"


class SmartLight final: public Device
{
	int brightnessLevel;

public:
	SmartLight();
	SmartLight(int brightnessLevel, const char* manufacturer, double price);

	void setBrightnessLevel(int brightnessLevel);
	int getBrightnessLevel() const;

	void turnOn() const override final;

	void turnOff() const override final;

	void printDetails() const override final;

};

