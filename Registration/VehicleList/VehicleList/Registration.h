#pragma once
#define NUMBER_SIZE 8
#include <iostream>
#include <cstring>
#pragma warning (disable:4996)



class Registration
{
	char number[NUMBER_SIZE + 1]; // + 1 за '\0'

	bool validRegNumber(const char* number) const;
	bool isNumber(char ch) const;
	bool isLetter(char ch) const;

public:

	Registration() = delete;
	Registration(const char* number);

	friend bool operator==(const Registration& lhs, const Registration& rhs);
	friend bool operator!=(const Registration& lhs, const Registration& rhs);

	friend std::ostream& operator<<(std::ostream& os, const Registration& reg);
	friend std::istream& operator>>(std::istream& is, Registration& reg);

	const char* getNumber() const;
};

