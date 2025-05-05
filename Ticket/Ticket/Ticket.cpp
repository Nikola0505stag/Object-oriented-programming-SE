#include "Ticket.h"

void Ticket::free()
{
	delete[] name;
	name = nullptr;
	price = 0.0;
}

void Ticket::copyFrom(const Ticket& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	price = other.price;
}

void Ticket::moveFrom(Ticket&& other)
{
	name = other.name;
	price = other.price;
	other.name = nullptr;
	other.price = 0.0;
}

Ticket::Ticket()
{
	setName("DEFAULT_NAME");
	setPrice(0.1);
}

Ticket::Ticket(const char* name, double price)
{
	setName(name);
	setPrice(price);
}

Ticket::Ticket(const Ticket& other)
{
	copyFrom(other);
}

Ticket::Ticket(Ticket&& other) noexcept
{
	moveFrom(std::move(other));
}

Ticket& Ticket::operator=(const Ticket& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Ticket& Ticket::operator=(Ticket&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Ticket::~Ticket()
{
	free();
}

void Ticket::setName(const char* name)
{
	if (!name)
		throw std::invalid_argument("Name is nullptr...");
	if (this->name == name) return;

	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Ticket::setPrice(double price)
{
	if (price <= 0.0)
		throw std::invalid_argument("Invalid price: must be a positive number...");
	this->price = price;
}

const char* Ticket::getName() const
{
	return name;
}

double Ticket::getPrice() const
{
	return price;
}

std::ostream& operator<<(std::ostream& os, const Ticket& ticket)
{
	os << "\n----------------------------------------------\n";
	os << "NAME: " << ticket.name << std::endl;
	os << "PRICE: " << ticket.price;
	os << "\n----------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Ticket& ticket)
{
	char buff[1024];
	is.getline(buff, 1024);
	ticket.setName(buff);
	is >> ticket.price;

	return is;
}
