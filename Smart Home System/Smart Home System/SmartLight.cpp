#include "SmartLight.h"

SmartLight::SmartLight() :Device()
{
	setBrightnessLevel(0);
}

SmartLight::SmartLight(int brightnessLevel, const char* manufacturer, double price):Device(manufacturer,price)
{
	setBrightnessLevel(brightnessLevel);
}

void SmartLight::setBrightnessLevel(int brightnessLevel)
{
	if (brightnessLevel < 0)
		throw std::invalid_argument("BrightnessLevel must be positive number...");
	if (brightnessLevel > 100)
		throw std::invalid_argument("BrightnessLevel must be bellow 100...");

	this->brightnessLevel = brightnessLevel;
}

int SmartLight::getBrightnessLevel() const
{
	return brightnessLevel;
}

void SmartLight::turnOn() const
{
	std::cout << "Smart Light turned on!";
}

void SmartLight::turnOff() const
{
	std::cout << "Smart Light turned off!";
}

void SmartLight::printDetails() const
{
	std::cout << "--------------------------------------\n";
	std::cout << "MANUFACTURER: " << getManufacturer() << "\n";
	std::cout << "PRICE: " << getPrice() << "\n";
	std::cout << "BRIGHTNESSLEVEL: " << getBrightnessLevel() << "\n";
	std::cout << "--------------------------------------\n";
}
