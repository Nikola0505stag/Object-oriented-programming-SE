#pragma once
#include "Component.h"

class Configuration
{

	Component** components;
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const Configuration& other);
	void resize(size_t newCapacity);
public:
	Configuration();
	Configuration(const Configuration& other);
	Configuration& operator= (const Configuration& other);
	~Configuration();
	
	void addItem(const Component& component);
	void printConfiguration() const;
};

