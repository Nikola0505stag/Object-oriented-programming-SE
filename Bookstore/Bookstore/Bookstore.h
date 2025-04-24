#pragma once
#include "Book.h"


class Bookstore {
	char* name;
	Book* books;
	int size;
	int capacity;

	
	void resize(int newCapacity);
	void copyFrom(const Bookstore& other);
	void free();


public:
	Bookstore();
	Bookstore(const Book* books, const char* name, int size, int capacity);
	Bookstore(const Bookstore& other); 
	Bookstore& operator=(const Bookstore& other);
	~Bookstore();

	void setName(const char* name);

	const char* getName() const;
	int getSize() const;
	int getCapacity() const;

	friend std::ostream& operator<<(std::ostream& os, const Bookstore& bookstore);

	Bookstore& operator+=(const Book& book);
};