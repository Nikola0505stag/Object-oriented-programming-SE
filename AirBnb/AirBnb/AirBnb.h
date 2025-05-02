#pragma once
#include "Accommodation.h"

class AirBnb {
	Accommodation* accommodations = nullptr;
	size_t size = 0;
	size_t capacity = 16;
	static int allPrice;

	void copyFrom(const AirBnb& other);
	void free();
	void resize(size_t newCapacity);

public:
	AirBnb();
	~AirBnb();
	AirBnb(const AirBnb& other);
	AirBnb& operator=(const AirBnb& other);

	AirBnb& operator+=(const Accommodation& accommodation);
	AirBnb& operator-=(int ID);

	void reserve(int ID, int days);
	void removeReservation(int ID);

	friend std::ostream& operator<<(std::ostream& os, const AirBnb& airbnb);

	double currPriceSum() const;

	static int getAllPrice();

	Accommodation printClosest(Location loc) const;
};