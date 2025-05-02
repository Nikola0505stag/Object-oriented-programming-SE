#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#pragma warning(disable:4996)

enum Type {
	Apartment,
	Hotel,
	Villa,
	DEFAULT_TYPE
};

struct Location {
	int x = 0;
	int y = 0;
};

class Accommodation {
	static int counter;
	size_t ID = 0;
	char* name = nullptr;
	Type type;
	Location location;
	double price;
	bool empty;
	size_t days;


	void free();
	void copyFrom(const Accommodation& other);

public:
	Accommodation();
	Accommodation(const char* name, Type type, Location location, double price, bool empty, size_t days);
	Accommodation(const Accommodation& other);
	Accommodation& operator=(const Accommodation& other);
	~Accommodation();

	void setName(const char* name);
	void setType(Type type);
	void setLocation(Location location);
	void setPrice(double price);
	void setEmpty(bool empty);
	void setDays(size_t days);

	const char* getName() const;
	Type getType() const;
	Location getLocation() const;
	double getPrice() const;
	bool getEmpty() const;
	size_t getDays() const;
	size_t getID() const;

	friend std::ostream& operator<<(std::ostream& os, const Accommodation& accommodation);
	friend std::istream& operator>>(std::istream& is, Accommodation& accommodation);
	
	void saveReservation(size_t days);
	void deleteReservation();

	int sum() const;
};

