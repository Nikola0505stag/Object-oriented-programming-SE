#include "Memory.h"

void Memory::setCapacity(unsigned short capacity)
{
    if (capacity >= 1 && capacity <= 10000)
        this->capacity = capacity;
    else
        throw std::invalid_argument("Capacity must be between 1 and 10000...");
}

Memory::Memory():Component("DEFAULT_LABEL")
{
    setCapacity(1);
}

Memory::Memory(unsigned short capacity, const char* label) : Component(label)
{
    setCapacity(capacity);
}

double Memory::price() const
{
    return 89.99 * capacity;
}

void Memory::output() const
{
    std::cout << "---------------------------------------\n";
    std::cout << "LABEL: " << getLabel() << "\n";
    std::cout << "CAPACITY: " << getCapacity() << "\n";
    std::cout << "PRICE: " << price() << "\n";
    std::cout << "---------------------------------------\n";
}

unsigned short Memory::getCapacity() const
{
    return capacity;
}

Component* Memory::clone() const
{
    return new Memory(*this);
}
