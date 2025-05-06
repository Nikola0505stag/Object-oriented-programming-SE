#include "Configuration.h"

void Configuration::free()
{
	for (int i = 0; i < size; i++) {
		delete components[i];
	}
	delete[] components;
}

void Configuration::copyFrom(const Configuration& other)
{
	capacity = other.capacity;
	size = other.size;

	components = new Component * [capacity];
	
	for (int i = 0; i < size; i++)
	{
		components[i] = other.components[i]->clone();
	}

}

void Configuration::resize(size_t newCapacity)
{
	Component** newArr = new Component * [newCapacity];

	for (size_t i = 0; i < size; ++i)
	{
		newArr[i] = components[i]; 
	}

	delete[] components;
	components = newArr;
	capacity = newCapacity;
}

Configuration::Configuration()
{
	capacity = 16;
	size = 0;
	components = new Component * [capacity];
	for (int i = 0; i < capacity; i++) {
		components[i] = nullptr;
	}
}

Configuration::Configuration(const Configuration& other)
{
	copyFrom(other);
}

Configuration& Configuration::operator=(const Configuration& other)
{
	if (this != &other){
		free();
		copyFrom(other);
	}
	return *this;
}

Configuration::~Configuration()
{
	free();
}

void Configuration::addItem(const Component& component)
{
	if (size >= capacity)
		resize(capacity * 2);

	components[size++] = component.clone(); 
}

void Configuration::printConfiguration() const
{
	for (int i = 0; i < size; i++) {
		components[i]->output();
	}
}
