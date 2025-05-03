#pragma once
#include "Registration.h"

class Vehicle
{
	Registration reg;
	char* description = nullptr;

	void free();
	void copyFrom(const Vehicle& other);
	void moveFrom(Vehicle&& other);

public:
	Vehicle() = delete;
	Vehicle(Registration reg, const char* description);
	Vehicle(const char* reg, const char* description);
	Vehicle(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(const Vehicle& other);
	Vehicle& operator=(Vehicle&& other) noexcept;
	~Vehicle();

	void setDescription(const char* description);

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
	friend std::istream& operator>>(std::istream& is, Vehicle& vehicle);

};

