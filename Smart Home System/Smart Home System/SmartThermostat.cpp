#include "SmartThermostat.h"

SmartThermostat::SmartThermostat():Device()
{
	setCurrTemp(10);
	setTargetTemp(10);
}

SmartThermostat::SmartThermostat(int currTemp, int targetTemp, const char* manufacturer, double price):Device(manufacturer,price)
{
	setCurrTemp(currTemp);
	setTargetTemp(targetTemp);
}

void SmartThermostat::setCurrTemp(int currTemp)
{
	this->currTemp = currTemp;
}

void SmartThermostat::setTargetTemp(int targetTemp)
{
	if (targetTemp < MIN_TEMP)
		throw std::invalid_argument("Dangerously low temperature...");
	if (targetTemp > MAX_TEMP)
		throw std::invalid_argument("Dangerously high temperature!...");

	this->targetTemp = targetTemp;
}

int SmartThermostat::getCurrTemp() const
{
	return currTemp;
}

int SmartThermostat::getTargetTemp() const
{
	return targetTemp;
}

void SmartThermostat::turnOn() const
{
	std::cout << "Smart Thermostat turned on!";
}

void SmartThermostat::turnOff() const
{
	std::cout << "Smart Thermostat turned off!";
}

void SmartThermostat::printDetails() const
{
	std::cout << "--------------------------------------\n";
	std::cout << "MANUFACTURER: " << getManufacturer() << "\n";
	std::cout << "PRICE: " << getPrice() << "\n";
	std::cout << "CURRENT TEMPERATURE: " << getCurrTemp() << "\n";
	std::cout << "TARGET TEMPERATURE: " << getTargetTemp() << "\n";
	std::cout << "--------------------------------------\n";
}
