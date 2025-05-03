#pragma once
#include "Vehicle.h"


class VehicleList
{
	Vehicle** vehicles = nullptr;
	size_t size;


	void moveFrom(VehicleList&& other);
	void copyFrom(const VehicleList& other);
	void free();


public:
	VehicleList() = delete;
	VehicleList(size_t size);
	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(VehicleList&& other) noexcept;
	~VehicleList();

	VehicleList operator+=(const Vehicle& vec);
	Vehicle& operator[](int index);
	const Vehicle& operator[](int index) const;
	Vehicle& operator()(const char* reg);
	const Vehicle& operator()(const char* reg) const;

};

