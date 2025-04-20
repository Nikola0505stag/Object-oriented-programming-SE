#include "Webpage.h"

void Webpage::copyFrom(const Webpage& other)
{
	address = new char[strlen(other.address) + 1];
	ip = new char[strlen(other.ip) + 1];

	strcpy(address, other.address);
	strcpy(ip, other.ip);
}

void Webpage::free()
{
	delete[] address;
	delete[] ip;

	address = nullptr;
	ip = nullptr;

}

Webpage::Webpage()
{
	setAddress(nullptr);
	setIp(nullptr);
}

Webpage::Webpage(const char* adress, const char* ip)
{
	setAddress(adress);
	setIp(ip);
}

Webpage::Webpage(const Webpage& other)
{
	copyFrom(other);
}

Webpage::~Webpage()
{
	free();
}

Webpage& Webpage::operator=(const Webpage& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

void Webpage::setAddress(const char* address)
{
	if (!address) {
		this->address = new char[strlen("DEFAULT_ADDRESS") + 1];
		strcpy(this->address, "DEFAULT_ADDRESS");
		return;
	}
	this->address = new char[strlen(address) + 1];
	strcpy(this->address, address);
}

void Webpage::setIp(const char* ip)
{
	if (!ip) {
		this->ip = new char[strlen("DEFAULT_IP") + 1];
		strcpy(this->ip, "DEFAULT_IP");
		return;
	}
	this->ip = new char[strlen(ip) + 1];
	strcpy(this->ip, ip);
}

const char* Webpage::getAddress() const
{
	return address;
}

const char* Webpage::getIp() const
{
	return ip;
}

std::ostream& operator<<(std::ostream& os, const Webpage& web)
{
	os << web.address << "\t" << web.ip;

	return os;
}

std::istream& operator>>(std::istream& is, Webpage& web)
{
	char buff[1000];
	is >> buff;
	web.setAddress(buff);
	is >> buff;
	web.setIp(buff);

	return is;

}
