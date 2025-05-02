#include "Accommodation.h"

int Accommodation::counter = 0;

void Accommodation::setName(const char* name)
{
	if (this->name == name) {
		return;
	}

	delete[] this->name;

	if (!name) {
		this->name = new char[strlen("DEFAULT_NAME") + 1];
		strcpy(this->name, "DEFAULT_NAME");
		return;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Accommodation::setType(Type type)
{
	this->type = type;
}

void Accommodation::setLocation(Location location)
{
	this->location.x = location.x;
	this->location.y = location.y;
}

void Accommodation::setPrice(double price)
{
	if (price <= 0) {
		this->price = 0.0;
	}
	else {
		this->price = price;
	}
}

void Accommodation::setEmpty(bool empty)
{
	this->empty = empty;
}

void Accommodation::setDays(size_t days)
{
	if (days <= 0) {
		this->days = 0;
	}
	else {
		this->days = days;
	}
}

const char* Accommodation::getName() const
{
	return name;
}

Type Accommodation::getType() const
{
	return type;
}

Location Accommodation::getLocation() const
{
	return location;
}

double Accommodation::getPrice() const
{
	return price;
}

bool Accommodation::getEmpty() const
{
	return empty;
}

size_t Accommodation::getDays() const
{
	return days;
}

size_t Accommodation::getID() const
{
	return ID;
}

void Accommodation::saveReservation(size_t days)
{
	this->days = days;
	empty = false;	
}

void Accommodation::deleteReservation()
{
	days = 0;
	empty = true;
}

int Accommodation::sum() const
{
	if (empty) return 0;
	else return days * price;
}

void Accommodation::free()
{
	delete[] name;
	name = nullptr;
	empty = true;
	type = Type::DEFAULT_TYPE;
	location.x = 0;
	location.y = 0;
	price = 0.0;
	days = 0;

}

void Accommodation::copyFrom(const Accommodation& other)
{
	ID = counter++;

	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	empty = other.empty;
	type = other.type;
	location.x = other.location.x;
	location.y = other.location.y;
	price = other.price;
	days = other.days;
}

Accommodation::Accommodation()
{
	setName("DEFAULT_NAME");
	setEmpty(true);
	setType(Type::DEFAULT_TYPE);
	setLocation({ 0,0 });
	setPrice(0.0);
	setDays(0);

	ID = counter++;
}

Accommodation::Accommodation(const char* name, Type type, Location location, double price, bool empty, size_t days)
{
	setName(name);
	setType(type);
	setLocation(location);
	setPrice(price);
	setEmpty(empty);
	setDays(days);

	ID = counter++;
}

Accommodation::Accommodation(const Accommodation& other)
{
	copyFrom(other);
}

Accommodation& Accommodation::operator=(const Accommodation& other)
{
	counter--;
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Accommodation::~Accommodation()
{
	free();
}

std::ostream& operator<<(std::ostream& os, const Accommodation& accommodation)
{
	os << "ID:" << accommodation.ID << "\n" << "NAME: " << accommodation.name << "\n";
	os << "TYPE:";
	switch (accommodation.type) {
		case Type::Apartment: os << "Apartment"; break;
		case Type::Hotel: os << "Hotel"; break;
		case Type::Villa:os << "Villa"; break;
		default: os << "DEFAULT_TYPE"; break;
	}

	os << "\nLOCATION:" << "( " << accommodation.location.x << " ; " << accommodation.location.y << " )\nPRICE:" <<
		accommodation.price << "\n";
	if (accommodation.empty) os << "Empty!\nDAYS:";
	else os << "Not empty!\nDAYS:";
	os << accommodation.days;

	return os;
}

std::istream& operator>>(std::istream& is, Accommodation& accommodation)
{
	char buff[1024];
	is.getline(buff, 1024);
	accommodation.setName(buff);

	int typeInt;
	is >> typeInt;
	accommodation.setType(static_cast<Type>(typeInt));

	Location loc;
	is >> loc.x >> loc.y;
	accommodation.setLocation(loc);

	double price;
	is >> price;
	accommodation.setPrice(price);

	int emptyFlag;
	is >> emptyFlag;
	accommodation.setEmpty(emptyFlag == 1);

	size_t days;
	is >> days;
	accommodation.setDays(days);

	return is;
}
