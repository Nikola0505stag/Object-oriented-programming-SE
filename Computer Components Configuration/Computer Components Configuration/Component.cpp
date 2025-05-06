#include "Component.h"

void Component::free()
{
	delete[] label;
	label = nullptr;
}

void Component::copyFrom(const Component& other)
{
	label = new char[strlen(other.label) + 1];
	strcpy(label, other.label);
}

void Component::moveFrom(Component&& other)
{
	label = other.label;
	other.label = nullptr;
}

void Component::setLabel(const char* label)
{
	if (!label)	
		throw std::invalid_argument("Label is nullptr...");
	if (this->label == label) return;

	delete[] this->label;

	this->label = new char[strlen(label) + 1];
	strcpy(this->label, label);
}

Component::Component(const char* lebel)
{
	setLabel(lebel);
}

Component::Component(const Component& other)
{
	copyFrom(other);
}

Component::Component(Component&& other) noexcept
{
	moveFrom(std::move(other));
}

Component& Component::operator=(const Component& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Component& Component::operator=(Component&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Component::~Component()
{
	free();
}

const char* Component::getLabel() const
{
	return label;
}
