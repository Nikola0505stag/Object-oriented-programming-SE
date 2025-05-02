#pragma once
#include "Computer.h"

class ComputerStore
{
	char* name = nullptr;
	Computer** computers = nullptr;
	size_t size; 
	size_t capacity;

	void free();
	void copyFrom(const ComputerStore& other);
	void resize(size_t newCapacity);

public:
	ComputerStore() = delete;
	ComputerStore(const char* name);
	ComputerStore(const ComputerStore& other);
	ComputerStore& operator=(const ComputerStore& other);
	~ComputerStore();


	void setName(const char* name);
	const char* getName() const;
	size_t getSize() const;
	size_t getCapacity() const;

	ComputerStore& operator+=(const Computer& computer);

	friend std::ostream& operator<<(std::ostream& os, const ComputerStore& cs);

	void buy(const char* brand, double money);

};

