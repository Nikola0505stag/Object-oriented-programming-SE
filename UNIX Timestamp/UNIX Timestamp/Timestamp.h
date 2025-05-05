#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)

class Timestamp
{
	unsigned int seconds;

public:
	Timestamp(); 
	Timestamp(unsigned int seconds);

	void setSeconds(unsigned int seconds);
	unsigned int getSeconds() const;

	friend std::ostream& operator<<(std::ostream& os, const Timestamp& timestamp);
	friend std::istream& operator>>(std::istream& is, Timestamp& timestamp);

	Timestamp& operator+=(unsigned int seconds);
};

