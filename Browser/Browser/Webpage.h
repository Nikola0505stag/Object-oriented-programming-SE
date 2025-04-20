#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)

class Webpage {
	char* address;
	char* ip;

	void copyFrom(const Webpage& other);
	void free();

public:
	Webpage();
	Webpage(const char* adress, const char* ip);
	Webpage(const Webpage& other);
	~Webpage();
	Webpage& operator=(const Webpage& other);

	void setAddress(const char* address);
	void setIp(const char* ip);

	const char* getAddress() const;
	const char* getIp() const;

	friend std::ostream& operator<<(std::ostream& os, const Webpage& web);
	friend std::istream& operator>>(std::istream& is, Webpage& web);

};
