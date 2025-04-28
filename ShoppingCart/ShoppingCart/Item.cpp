#include "Item.h"

void Item::free()
{
	delete[] name;
	name = nullptr;
	quantity = 0;
	price = 0.0;
}

void Item::copyFrom(const Item& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->quantity = other.quantity;
	this->price = other.price;
}

Item::Item()
{
	setName("DEFAULT_NAME");
	setPrice(0.0);
	setQuantity(0);
}

Item::Item(const char* name, int quantity, double price)
{
	setName(name);
	setQuantity(quantity);
	setPrice(price);
}

Item::Item(const Item& other)
{
	copyFrom(other);
}

Item& Item::operator=(const Item& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Item::~Item()
{
	free();
}

void Item::setName(const char* name)
{
	if (this->name == name)
		return;

	delete[] this->name;

	if (!name) {
		this->name = new char[strlen("DEFAULT_NAME") + 1];
		strcpy(this->name, "DEFAULT_NAME");
		return;
	}
	
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	
}

void Item::setQuantity(int quantity)
{
	if (quantity <= 0)
		this->quantity = 0;
	else
		this->quantity = quantity;
}

void Item::setPrice(double price)
{
	if (price <= 0)
		this->price = 0.0;
	else
		this->price = price;
}

const char* Item::getName() const
{
	return name;
}

int Item::getQuantity() const
{
	return quantity;
}

double Item::getPrice() const
{
	return price;
}

void Item::writeInFile(std::ofstream& ofs) const
{
	int nameLen = strlen(name) + 1;
	ofs.write((const char*)&nameLen, sizeof(nameLen));
	ofs.write((const char*)name, nameLen);
	ofs.write((const char*)&quantity, sizeof(quantity));
	ofs.write((const char*)&price, sizeof(price));
}

void Item::readFromFile(std::ifstream& ifs)
{
	free();

	int nameLen;
	ifs.read((char*)&nameLen, sizeof(nameLen));

	name = new char[nameLen];

	ifs.read((char*)name, nameLen);

	ifs.read((char*)&quantity, sizeof(quantity));
	ifs.read((char*)&price, sizeof(price));
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
	os << "-----------------------------------------" << std::endl;
	os << item.name << "\t" << item.quantity << "\t" << item.price << std::endl;
	os << "-----------------------------------------" << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Item& item)
{
	char buff[1024];
	is.getline(buff, 1024);

	item.setName(buff);


	is >> item.quantity;
	is >> item.price;

	return is;
}
