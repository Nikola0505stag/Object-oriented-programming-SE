#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)


class Computer
{
	int ID;
	static int counter;
	char* brand = nullptr;
	char* processor = nullptr;
	int video;
	int hardDrive;
	int weight;
	int batteryLife;
	double price;
	int quantity;

	void free();
	void copyFrom(const Computer& other);

public:
	Computer() = delete;
	Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife,
		double price, int quantity);
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	~Computer();

	int getID() const;
	const char* getBrand() const;
	const char* getProcessor() const;
	int getVideo() const;
	int getHardDrive() const;
	int getWeight() const;
	int getBatteryLife() const;
	double getPrice() const;
	int getQuantity() const;

	void setQuantity(int quantity);

	friend std::ostream& operator<<(std::ostream& os, const Computer& computer);

	Computer& operator+=(int quantity);
	Computer& operator-=(int quantity);

	friend bool operator==(const Computer& lhs, const Computer& rhs);

};

