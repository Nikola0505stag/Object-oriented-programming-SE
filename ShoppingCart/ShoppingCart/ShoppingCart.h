#pragma once
#include "Item.h"

class ShoppingCart {
	Item* items = nullptr;
	int size;
	int capacity;

	void copyFrom(const ShoppingCart& other);
	void free();
	void resize(int newCapacity);

	int findIndex(const char* name) const;

public:
	ShoppingCart();
	ShoppingCart(Item* items, int size);
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart& operator=(const ShoppingCart& other);
	~ShoppingCart();

	int getSize() const;
	int getCapacity() const;

	friend std::ostream& operator<<(std::ostream& os, const ShoppingCart& sh);
	friend std::istream& operator>>(std::istream& is, ShoppingCart& sh);

	ShoppingCart& operator+=(const Item& item);
	ShoppingCart& operator-=(const char* name);

	ShoppingCart& addItem(const Item& item);
	ShoppingCart& removeItem(const char* name);
	int itemsCount() const;

	bool exists(const char* name) const;
	bool isEmpty() const;

	double getPriceOf(const char* name) const;
	double totalPrice() const;

	void saveToBinary(std::ofstream& ofs) const;
	void readFromBinary(std::ifstream& ifs);

};