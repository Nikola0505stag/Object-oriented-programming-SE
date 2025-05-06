#include "SmartSpeaker.h"

SmartSpeaker::SmartSpeaker():Device()
{
	setVolume(0.0);
}

SmartSpeaker::SmartSpeaker(double volume, const char* manufacturer, double price) :Device(manufacturer, price)
{
	setVolume(volume);
}

void SmartSpeaker::setVolume(double volume)
{
	if (volume < 0)
		throw std::invalid_argument("Volume must be positive number...");
	this->volume = volume;
}

double SmartSpeaker::getVolume() const
{
	return volume;
}

void SmartSpeaker::turnOn() const
{
	std::cout << "Smart Speaker turned on!";
}

void SmartSpeaker::turnOff() const
{
	std::cout << "Smart Speaker turned off!";
}

void SmartSpeaker::printDetails() const
{
	std::cout << "--------------------------------------\n";
	std::cout << "MANUFACTURER: " << getManufacturer() << "\n";
	std::cout << "PRICE: " << getPrice() << "\n";
	std::cout << "VOLUME: " << getVolume() << "\n";
	std::cout << "--------------------------------------\n";
}
