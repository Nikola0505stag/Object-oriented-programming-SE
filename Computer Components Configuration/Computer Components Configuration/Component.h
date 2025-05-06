#pragma once
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)

class Component
{
	char* label;

	void free();
	void copyFrom(const Component& other);
	void moveFrom(Component&& other);

	void setLabel(const char* label);

public:
	Component() = delete;
	Component(const char* lebel);
	Component(const Component& other);
	Component(Component&& other) noexcept;
	Component& operator=(const Component& other);
	Component& operator=(Component&& other) noexcept;
	virtual ~Component();

	virtual double price() const = 0;
	virtual void output() const = 0;
	virtual Component* clone() const = 0;

	const char* getLabel() const;
};

