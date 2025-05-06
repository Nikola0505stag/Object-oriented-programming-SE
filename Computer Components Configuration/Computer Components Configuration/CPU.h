#pragma once
#include "Component.h"


class CPU final : public Component
{
	unsigned short cores;
	unsigned short clockSpeed;

public:
	CPU();
	CPU(unsigned short cores, unsigned short clockSpeed, const char* label);

	void setCores(unsigned short cores);
	void setClockSpeed(unsigned short clockSpeed);

	unsigned short getCores() const;
	unsigned short getClockSpeed() const;

	double price() const override final;
	void output() const override;


	// Inherited via Component
	Component* clone() const override;

};

