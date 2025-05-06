#pragma once
#include "Device.h"
#define MIN_TEMP 5
#define MAX_TEMP 35


class SmartThermostat final : public Device
{
	int currTemp;
	int targetTemp;

public:
	SmartThermostat();
	SmartThermostat(int currTemp, int targetTemp, const char* manufacturer, double price);

	void setCurrTemp(int currTemp);
	void setTargetTemp(int targetTemp);

	int getCurrTemp() const;
	int getTargetTemp() const;

	void turnOn() const override final;

	void turnOff() const override final;

	void printDetails() const override final;

};

