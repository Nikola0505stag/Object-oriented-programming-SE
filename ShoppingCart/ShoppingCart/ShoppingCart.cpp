#include "ShoppingCart.h"

void ShoppingCart::copyFrom(const ShoppingCart& other)
{
	size = other.size;
	capacity = other.capacity;

	items = new Item[capacity];

	for (int i = 0; i < size; i++) {
		items[i] = other.items[i];
	}
}

void ShoppingCart::free()
{
	delete[] items;
	items = nullptr;
	size = 0;
	capacity = 0;
}

void ShoppingCart::resize(int newCapacity)
{
	Item* newItems = new Item[newCapacity];

	capacity = newCapacity;
	
	for (int i = 0; i < size; i++) {
		newItems[i] = this->items[i];
	}

	delete[] this->items;

	this->items = newItems;

	newItems = nullptr;
}

int ShoppingCart::findIndex(const char* name) const
{
	for (int i = 0; i < size; i++) {
		if (strcmp(items[i].getName(), name) == 0)
			return i;
	}
	return -1;
}

ShoppingCart::ShoppingCart()
{
	capacity = 16;
	size = 0;
	items = new Item[capacity];
}

ShoppingCart::ShoppingCart(Item* items, int size)
{
	this->size = size;
	
	capacity = size * 2;

	this->items = new Item[capacity];


	for (int i = 0; i < size; i++) {
		this->items[i] = items[i];
	}

}

ShoppingCart::ShoppingCart(const ShoppingCart& other)
{
	copyFrom(other);
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ShoppingCart::~ShoppingCart()
{
	free();
}

int ShoppingCart::getSize() const
{
	return size;
}

int ShoppingCart::getCapacity() const
{
	return capacity;
}

ShoppingCart& ShoppingCart::operator+=(const Item& item)
{
	if (size >= capacity)
		resize(capacity * 2);
	
	this->items[size++] = item;

	return *this;
}

ShoppingCart& ShoppingCart::operator-=(const char* name)
{
	int index = findIndex(name);

	if (index == -1)
		return *this;

	std::swap(items[index], items[size - 1]);
	size--;

	return *this;
}

ShoppingCart& ShoppingCart::addItem(const Item& item)
{
	return operator+=(item);
}

ShoppingCart& ShoppingCart::removeItem(const char* name)
{
	return operator-=(name);
}

int ShoppingCart::itemsCount() const
{
	return getSize();
}

bool ShoppingCart::exists(const char* name) const
{
	int index = findIndex(name);

	return index != -1;
}

bool ShoppingCart::isEmpty() const
{
	return getSize() >= 1;
}

double ShoppingCart::getPriceOf(const char* name) const
{
	int index = findIndex(name);
	return index != -1 ? items[index].getPrice() : 0.0;
}

double ShoppingCart::totalPrice() const
{
	double price = 0.0;

	for (int i = 0; i < size; i++) {
		price += items[i].getPrice();
	}
	return price;
}

void ShoppingCart::saveToBinary(std::ofstream& ofs) const
{
	ofs.write((const char*)&size, sizeof(size));
	ofs.write((const char*)&capacity, sizeof(capacity));

	for (int i = 0; i < size; i++) {
		items[i].writeInFile(ofs);
	}

}

void ShoppingCart::readFromBinary(std::ifstream& ifs)
{
	free();

	ifs.read((char*)&size, sizeof(size));
	ifs.read((char*)&capacity, sizeof(capacity));

	items = new Item[capacity];

	for (int i = 0; i < size; i++) {
		items[i].readFromFile(ifs);
	}
}

std::ostream& operator<<(std::ostream& os, const ShoppingCart& sh)
{
	os << std::endl << std::endl;
	os << "CART:" << std::endl;
	os << "-----------------------------------------" << std::endl;
	for (int i = 0; i < sh.size; i++) {
		os << sh.items[i];
	}
	os << "-----------------------------------------" << std::endl;
	
	return os;
}

std::istream& operator>>(std::istream& is, ShoppingCart& sh)
{
	is >> sh.size;
	sh.capacity = sh.size * 2;

	for (int i = 0; i < sh.size; i++) {
		is >> sh.items[i];
	}
	return is;
}
