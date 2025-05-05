#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
#pragma warning (disable:4996)

class Ticket
{
	char* name = nullptr;
	double price;

	void free();
	void copyFrom(const Ticket& other);
	void moveFrom(Ticket&& other);

public:
	Ticket();
	Ticket(const char* name, double price);
	Ticket(const Ticket& other);
	Ticket(Ticket&& other) noexcept;
	Ticket& operator=(const Ticket& other);
	Ticket& operator=(Ticket&& other) noexcept;
	~Ticket();

	void setName(const char* name);
	void setPrice(double price);

	const char* getName() const;
	double getPrice() const;

	friend std::ostream& operator<<(std::ostream& os, const Ticket& ticket);
	friend std::istream& operator>>(std::istream& is, Ticket& ticket);

};

