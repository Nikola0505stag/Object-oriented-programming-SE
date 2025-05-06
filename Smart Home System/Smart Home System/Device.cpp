#include "Device.h"

void Device::free()
{
	delete[] manufacturer;
	manufacturer = nullptr;
	price = 0.0;
}

void Device::copyFrom(const Device& other)
{
	manufacturer = new char[strlen(other.manufacturer) + 1];
	strcpy(manufacturer, other.manufacturer);
	price = other.price;
}

void Device::moveFrom(Device&& other)
{
	manufacturer = other.manufacturer;
	price = other.price;

	other.manufacturer = nullptr;
	other.price = 0.0;
}

Device::Device()
{
	setManufacturer("DEFAULT_MANUFACTURER");
	setPrice(0.1);
}

Device::Device(const char* manufacturer, double price)
{
	setManufacturer(manufacturer);
	setPrice(price);
}

Device::Device(const Device& other)
{
	copyFrom(other);
}

Device::Device(Device&& other) noexcept
{
	moveFrom(std::move(other));
}

Device& Device::operator=(const Device& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Device& Device::operator=(Device&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Device::~Device()
{
	free();
}

void Device::setManufacturer(const char* manufacturer)
{
	if (!manufacturer)
		throw std::invalid_argument("Manufacturer is nullptr...");
	
	if (this->manufacturer == manufacturer)
		return;

	delete[] this->manufacturer;

	this->manufacturer = new char[strlen(manufacturer) + 1];
	strcpy(this->manufacturer, manufacturer);
}

void Device::setPrice(double price)
{
	if (price <= 0)
		throw std::invalid_argument("Price must be positive number...");
	this->price = price;
}

const char* Device::getManufacturer() const
{
	return manufacturer;
}

double Device::getPrice() const
{
	return price;
}
