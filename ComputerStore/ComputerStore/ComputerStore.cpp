#include "ComputerStore.h"

void ComputerStore::free()
{
	delete[] name; name = nullptr;
	for (int i = 0; i < size; i++) {
		delete computers[i];
	}
	delete[] computers;

	size = 0;
	capacity = 0;
}

void ComputerStore::copyFrom(const ComputerStore& other)
{
	size = other.size;
	capacity = other.capacity;

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	computers = new Computer*[capacity];

	for (int i = 0; i < size; i++) {
		computers[i] = new Computer(*other.computers[i]);
	}
	
}

void ComputerStore::resize(size_t newCapacity)
{
	Computer** newComputers = new Computer*[newCapacity];
	
	for (int i = 0; i < size; i++) {
		newComputers[i] = new Computer(*computers[i]);
		delete computers[i];
	}
	delete[] computers;

	capacity = newCapacity;
	computers = newComputers;

}

ComputerStore::ComputerStore(const char* name)
{
	size = 0;
	capacity = 16;
	setName(name);
	computers = new Computer * [capacity] {nullptr};

}

ComputerStore::ComputerStore(const ComputerStore& other)
{
	copyFrom(other);
}

ComputerStore& ComputerStore::operator=(const ComputerStore& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

ComputerStore::~ComputerStore()
{
	free();
}

void ComputerStore::setName(const char* name)
{
	if (name == this->name) return;

	delete[] this->name;

	if (!name) {
		this->name = new char[strlen("DEFAULT_NAME") + 1];
		strcpy(this->name, "DEFAULT_NAME");
		throw std::runtime_error("Name is nullptr...");
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* ComputerStore::getName() const
{
	return name;
}

size_t ComputerStore::getSize() const
{
	return size;
}

size_t ComputerStore::getCapacity() const
{
	return capacity;
}

ComputerStore& ComputerStore::operator+=(const Computer& computer)
{
	for (int i = 0; i < size; i++) {
		if (*computers[i] == computer) {
			computers[i]->setQuantity(computers[i]->getQuantity() + 1);
			return *this;
		}
	}

	if (size >= capacity)
		resize(capacity * 2);

	computers[size] = new Computer(computer);

	size++;
	return *this;
}

void ComputerStore::buy(const char* brand, double money)
{
	for (int i = 0; i < size; i++) {
		if (strcmp(computers[i]->getBrand(), brand) == 0) {
			if (money >= computers[i]->getPrice()) {
				if (computers[i]->getQuantity() <= 0)
					throw std::runtime_error("Out of stock!");
				else { computers[i]->setQuantity(computers[i]->getQuantity() - 1); return;}
			}
			else {
				throw std::invalid_argument("Poor...");
			}
		}
	}
	throw std::invalid_argument("Wrong brand!");
}

std::ostream& operator<<(std::ostream& os, const ComputerStore& cs)
{
	os << "\n---------------------------------------\n";
	os << "---------------------------------------\n";
	os << "---------------------------------------\n";
	os << "NAME: " << cs.name << std::endl;
	os << "---------------------------------------\n";
	for (int i = 0; i < cs.size; i++) {
		os << *cs.computers[i];
	}

	os << "\n---------------------------------------\n";
	os << "---------------------------------------\n";
	os << "---------------------------------------\n";

	return os;
}
