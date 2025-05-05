#include "Timestamp.h"

Timestamp::Timestamp()
{
	seconds = 0;
}

Timestamp::Timestamp(unsigned int seconds)
{
	setSeconds(seconds);
}

void Timestamp::setSeconds(unsigned int seconds)
{
	if (seconds < 0)
		throw std::invalid_argument("Seconds must be positive number...");
	this->seconds = seconds;
}

unsigned int Timestamp::getSeconds() const
{
	return seconds;
}

Timestamp& Timestamp::operator+=(unsigned int seconds)
{
	if (seconds < 0)
		throw std::invalid_argument("Seconds must be positive number...");
	
	this->seconds += seconds;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Timestamp& timestamp)
{
	os << "-----------------------------------------------\n";
	os << "SECONDS: " << timestamp.seconds << std::endl;
	os << "-----------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Timestamp& timestamp)
{
	int curr;
	is >> curr;
	timestamp.setSeconds(curr);

	return is;

}
