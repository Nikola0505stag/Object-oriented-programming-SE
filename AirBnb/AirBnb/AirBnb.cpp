#include "AirBnb.h"

int AirBnb::allPrice = 0;

void AirBnb::copyFrom(const AirBnb& other)
{
	accommodations = new Accommodation[other.capacity];
	capacity = other.capacity;
	size = other.size;

	for (int i = 0; i < size; i++) {
		accommodations[i] = other.accommodations[i];
	}
}

void AirBnb::free()
{
	delete[] accommodations;
	accommodations = nullptr;

	size = 0;
	capacity = 0;
}

void AirBnb::resize(size_t newCapacity)
{
	Accommodation* newAccommodations = new Accommodation[newCapacity];
	for (int i = 0; i < size; i++) {
		newAccommodations[i] = accommodations[i];
	}

	delete[] accommodations;

	capacity = newCapacity;
	accommodations = newAccommodations;
}

AirBnb::AirBnb()
{
	size = 0;
	capacity = 16;
	accommodations = new Accommodation[capacity];
}

AirBnb::~AirBnb()
{
	free();

}

AirBnb::AirBnb(const AirBnb& other)
{
	copyFrom(other);
}

AirBnb& AirBnb::operator=(const AirBnb& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

AirBnb& AirBnb::operator+=(const Accommodation& accommodation)
{
	if (size >= capacity)
		resize(capacity * 2);

	accommodations[size++] = accommodation;

	return *this;
}

AirBnb& AirBnb::operator-=(int ID)
{
	for (int i = 0; i < size; i++) {
		if (accommodations[i].getID() == ID && !accommodations[i].getEmpty()) {
			std::swap(accommodations[i], accommodations[size - 1]);
			size--;
			return *this;
		}
	}
	throw std::invalid_argument("Wrong ID in operator-=");
}

void AirBnb::reserve(int ID, int days)
{
	for (int i = 0; i < size; i++) {
		if (ID == accommodations[i].getID()) {
			accommodations[i].saveReservation(days);
			allPrice += accommodations[i].getDays() * accommodations[i].getPrice();
			return;
		}
	}
	throw std::invalid_argument("Wrong ID int Reserve!");
}

void AirBnb::removeReservation(int ID)
{
	for (int i = 0; i < size; i++) {
		if (ID == accommodations[i].getID()) {
			accommodations[i].deleteReservation();
			return;
		}
	}
	throw std::invalid_argument("Wrong ID int removeReservation!");
}

double AirBnb::currPriceSum() const
{
	double price = 0;

	for (int i = 0; i < size; i++) {
		if (!accommodations[i].getEmpty()) {
			price += accommodations[i].getDays() * accommodations[i].getPrice();
		}
	}

	return price;
}

int AirBnb::getAllPrice()
{
	return allPrice;
}

Accommodation AirBnb::printClosest(Location loc) const
{

	if (size == 0) {
		throw std::runtime_error("No accommodations available");
	}

	double minDistance = std::numeric_limits<double>::max();
	Accommodation closest;

	for (int i = 0; i < size; i++) {
		double dx = accommodations[i].getLocation().x - loc.x;
		double dy = accommodations[i].getLocation().y - loc.y;
		double distance = std::sqrt(dx * dx + dy * dy);

		if (distance < minDistance) {
			minDistance = distance;
			closest = accommodations[i];
		}
	}

	return closest;
}

std::ostream& operator<<(std::ostream& os, const AirBnb& airbnb)
{
	os << "-------------------------------------------\n";
	os << "-------------------------------------------\n\n";

	for (int i = 0; i < airbnb.size; i++) {
		os << airbnb.accommodations[i];
	}

	os << "\n\n-------------------------------------------\n";
	os << "-------------------------------------------\n\n";

	return os;
}
