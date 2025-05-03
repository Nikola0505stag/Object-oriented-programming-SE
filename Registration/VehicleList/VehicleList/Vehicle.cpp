#include "Vehicle.h"

void Vehicle::free()
{
	delete[] description;

	description = nullptr;
}

void Vehicle::copyFrom(const Vehicle& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
	
	reg = other.reg;
}

void Vehicle::moveFrom(Vehicle&& other)
{
	description = other.description;
	other.description = nullptr;
	reg = other.reg;
}

Vehicle::Vehicle(Registration reg, const char* description): reg(reg)
{
	setDescription(description);
}

Vehicle::Vehicle(const char* reg, const char* description) : reg(reg)
{
	setDescription(description);
}

Vehicle::Vehicle(const Vehicle& other): reg(other.reg)
{
	copyFrom(other);
}

Vehicle::Vehicle(Vehicle&& other) noexcept : reg(other.reg)
{
	moveFrom(std::move(other));
}

Vehicle& Vehicle::operator=(const Vehicle& other)
{
	if (!&other) return *this;

	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Vehicle& Vehicle::operator=(Vehicle&& other) noexcept
{
	if (!&other) return *this;

	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	free();
}

void Vehicle::setDescription(const char* description)
{
	if (this->description == description)
		return;
	delete[] this->description;

	if (!description) {
		this->description = new char[strlen("DEFAULT_DESCRIPTION") + 1];
		strcpy(this->description, "DEFAULT_DESCRIPTION");
		return;
	}

	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle)
{
	os << "----------------------------------------------\n";
	os << "REGISTRATION: " << vehicle.reg;
	os << "DESCRIPTION: " << vehicle.description << "\n";
	os << "----------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Vehicle& vehicle)
{
	is >> vehicle.reg; is.ignore();
	char buff[1024];
	is.getline(buff, 1024);

	vehicle.setDescription(buff);

	return is;
}
