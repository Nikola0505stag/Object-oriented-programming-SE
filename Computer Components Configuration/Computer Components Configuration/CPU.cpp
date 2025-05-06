#include "CPU.h"

double CPU::price() const
{
	return 29.99 * cores;
}

void CPU::output() const
{
	std::cout << "---------------------------------------\n";
	std::cout << "LABEL: " << getLabel() << "\n";
	std::cout << "CORES: " << getCores() << "\n";
	std::cout << "CLOCK SPEED: " << getClockSpeed() << "\n";
	std::cout << "PRICE: " << price() << "\n";
	std::cout << "---------------------------------------\n";
}

Component* CPU::clone() const
{
	return new CPU(*this);
}

CPU::CPU():Component("DEFAULT_LABEL")
{
	setCores(1);
	setClockSpeed(0);
}

CPU::CPU(unsigned short cores, unsigned short clockSpeed, const char* label) : Component(label)
{
	setCores(cores);
	setClockSpeed(clockSpeed);
}

void CPU::setCores(unsigned short cores)
{
	if (cores >= 1 && cores <= 8)
		this->cores = cores;
	else
		throw std::invalid_argument("Wrong amount of cores...");
}

void CPU::setClockSpeed(unsigned short clockSpeed)
{
	this->clockSpeed = clockSpeed;
}

unsigned short CPU::getCores() const
{
	return cores;
}

unsigned short CPU::getClockSpeed() const
{
	return clockSpeed;
}
