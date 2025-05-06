#pragma once
#include "Device.h"

class SmartSpeaker final : public Device
{
	double volume;

public:
	SmartSpeaker();
	SmartSpeaker(double volume, const char* manufacturer, double price);

	void setVolume(double volume);
	double getVolume() const;

	void turnOn() const override final;

	void turnOff() const override final;

	void printDetails() const override final;

};

