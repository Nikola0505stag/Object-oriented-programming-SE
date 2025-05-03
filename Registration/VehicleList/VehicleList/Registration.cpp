#include "Registration.h"

bool Registration::validRegNumber(const char* number) const
{
	if (!number) return false;
	if (strlen(number) > 8 || strlen(number) < 7) return false;

	if (!isLetter(number[0])) return false;

	if (isLetter(number[1])) {
		if (!isNumber(number[2]) ||
			!isNumber(number[3]) ||
			!isNumber(number[4]) ||
			!isNumber(number[5])
			) return false;
		if (!isLetter(number[6]) ||
			!isLetter(number[7])
			) return false;

		return true;
	}
	else {
		if (!isNumber(number[1]) ||
			!isNumber(number[2]) ||
			!isNumber(number[3]) ||
			!isNumber(number[4])
			) return false;

		if (!isLetter(number[5]) ||
			!isLetter(number[6])
			) return false;

		return true;
	}
	
}

bool Registration::isNumber(char ch) const
{
	return ch >= '0' && ch <= '9';
}

bool Registration::isLetter(char ch) const
{
	return ch >= 'A' && ch <= 'Z';
}

Registration::Registration(const char* number)
{
	if (!number) {
		strcpy(this->number, "AA0000AA");
		return;
	}

	if (validRegNumber(number)) {
		strcpy(this->number, number);
	}
	else {
		strcpy(this->number, "AA0000AA");
	}
}

const char* Registration::getNumber() const
{
	return number;
}

bool operator==(const Registration& lhs, const Registration& rhs)
{
	return (strcmp(lhs.getNumber(), rhs.getNumber()) == 0);
}

bool operator!=(const Registration& lhs, const Registration& rhs)
{
	return !(lhs==rhs);
}

std::ostream& operator<<(std::ostream& os, const Registration& reg)
{
	os << reg.number << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Registration& reg)
{
	char buff[1024];
	is >> buff;
	Registration temp(buff);

	reg = temp;

	return is;
}
