#include "VehicleList.h"

void VehicleList::moveFrom(VehicleList&& other)
{
	size = other.size;

	vehicles = other.vehicles;

	other.vehicles = nullptr;
	other.size = 0;
}

void VehicleList::copyFrom(const VehicleList& other)
{
	size = other.size;

	vehicles = new Vehicle * [size];
	for (int i = 0; i < size; i++) {
		vehicles[i] = new Vehicle(*other.vehicles[i]);
	}
}

void VehicleList::free()
{
	for (int i = 0; i < size; i++)
		delete vehicles[i];

	delete[] vehicles;
	vehicles = nullptr;
	size = 0;
}

VehicleList::VehicleList(size_t size)
{
	this->size = size;

	vehicles = new Vehicle * [size] {nullptr};

	for (int i = 0; i < size; ++i) {
		vehicles[i] = nullptr;
	}
}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

VehicleList::VehicleList(VehicleList&& other) noexcept
{
	moveFrom(std::move(other));
}

VehicleList& VehicleList::operator=(VehicleList&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

VehicleList& VehicleList::operator+=(const Vehicle& vec)
{

	vehicles[size] = new Vehicle(vec);

	++size;

	return *this;
}

Vehicle& VehicleList::operator[](int index)
{
	return *vehicles[index];
}

const Vehicle& VehicleList::operator[](int index) const
{
	return *vehicles[index];
}


