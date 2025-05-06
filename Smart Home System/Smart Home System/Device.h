#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

class Device
{
	char* manufacturer = nullptr;
	double price;

	void free();
	void copyFrom(const Device& other);
	void moveFrom(Device&& other);

public:
	Device();
	Device(const char* manufacturer, double price);
	Device(const Device& other);
	Device(Device&& other) noexcept;
	Device& operator=(const Device& other);
	Device& operator=(Device&& other) noexcept;
	virtual ~Device();

	void setManufacturer(const char* manufacturer);
	void setPrice(double price);

	const char* getManufacturer() const;
	double getPrice() const;

	virtual void turnOn() const = 0;
	virtual void turnOff() const = 0;
	virtual void printDetails() const = 0;
};

