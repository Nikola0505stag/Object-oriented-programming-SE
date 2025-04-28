#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)

class Item {
	char* name = nullptr;
	int quantity;
	double price;

	void free();
	void copyFrom(const Item& other);

public:

	Item();
	Item(const char* name, int quantity, double price);
	Item(const Item& other);
	Item& operator= (const Item& other);
	~Item();

	void setName(const char* name);
	void setQuantity(int quantity);
	void setPrice(double price);

	const char* getName() const;
	int getQuantity() const;
	double getPrice() const;
	
	friend std::ostream& operator<<(std::ostream& os,const Item& item);
	friend std::istream& operator>>(std::istream& is, Item& item);

	void writeInFile(std::ofstream& ofs) const; 
	void readFromFile(std::ifstream& ifs);
};