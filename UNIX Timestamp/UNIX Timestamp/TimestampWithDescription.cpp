#include "TimestampWithDescription.h"

void TimestampWithDescription::free()
{
	delete[] description;
	description = nullptr;
}

void TimestampWithDescription::copyFrom(const TimestampWithDescription& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy(description, other.description);
}

void TimestampWithDescription::moveFrom(TimestampWithDescription&& other)
{
	description = other.description;
	other.description = nullptr;
}

TimestampWithDescription::TimestampWithDescription() : Timestamp()
{
	setDescription("DEFAULT_DESCRIPTION");
}

TimestampWithDescription::TimestampWithDescription(int seconds, const char* description):Timestamp(seconds)
{
	setDescription(description);
}

TimestampWithDescription::TimestampWithDescription(const TimestampWithDescription& other):Timestamp(other.getSeconds())
{
	copyFrom(other);
}

TimestampWithDescription::TimestampWithDescription(TimestampWithDescription&& other) noexcept : Timestamp(other.getSeconds())
{
	moveFrom(std::move(other));
}

TimestampWithDescription& TimestampWithDescription::operator=(const TimestampWithDescription& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
		Timestamp::Timestamp(other.getSeconds());
	}
	return *this;
}

TimestampWithDescription& TimestampWithDescription::operator=(TimestampWithDescription&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
		Timestamp::Timestamp(other.getSeconds());
	}
	return *this;
}

TimestampWithDescription::~TimestampWithDescription()
{
	free();
}

void TimestampWithDescription::setDescription(const char* description)
{
	if (!description)
		throw std::invalid_argument("Description is nullptr...");
	if (this->description == description)
		return;
	
	delete[] this->description;
	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

const char* TimestampWithDescription::getDescription() const
{
	return description;
}

std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& timestampwithdescription)
{
	os << "-----------------------------------------\n";
	os << "DESCRIPTION: " << timestampwithdescription.getDescription() << std::endl;
	os << "SECONDS: " << timestampwithdescription.getSeconds() << std::endl;
	os << "-----------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, TimestampWithDescription& timestampwithdescription)
{
	char buff[1024];
	is.getline(buff, 1024);
	timestampwithdescription.setDescription(buff);
	
	int curr;
	is >> curr;
	timestampwithdescription.setSeconds(curr);

	return is;
}
