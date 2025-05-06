#pragma once
#include "Component.h"


class Memory final : public Component
{

	unsigned short capacity;

	void setCapacity(unsigned short capacity);

public:
	Memory();
	Memory(unsigned short capacity, const char* label);

	double price() const override;

	void output() const override;

	unsigned short getCapacity() const;

	// Inherited via Component
	Component* clone() const override;
};

