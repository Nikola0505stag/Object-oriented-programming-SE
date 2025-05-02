#include "Computer.h"

int Computer::counter = 0;

void Computer::free()
{
	delete[] brand; brand = nullptr;
	delete[] processor; processor = nullptr;

	video = hardDrive = weight = batteryLife = quantity = 0;
	price = 0.0;
}

void Computer::copyFrom(const Computer& other)
{
	brand = new char[strlen(other.brand) + 1];
	strcpy(brand, other.brand);

	processor = new char[strlen(other.processor) + 1];
	strcpy(processor, other.processor);

	ID = ++counter;

	video = other.video;
	hardDrive = other.hardDrive;
	weight = other.weight;
	batteryLife = other.batteryLife;
	price = other.price;
	quantity = other.quantity;
}

Computer::Computer(const char* brand, const char* processor, int video, int hardDrive, int weight, int batteryLife, double price,
	int quantity)
{
	ID = ++counter;
	this->brand = new char[strlen(brand) + 1];
	strcpy(this->brand, brand);

	this->processor = new char[strlen(processor) + 1];
	strcpy(this->processor, processor);
	
	this->video = video;
	this->hardDrive = hardDrive;
	this->weight = weight;
	this->batteryLife = batteryLife;
	this->price = price;
	this->quantity = quantity;
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	
	return *this;

}

Computer::~Computer()
{
	free();
}

int Computer::getID() const
{
	return ID;
}

const char* Computer::getBrand() const
{
	return brand;
}

const char* Computer::getProcessor() const
{
	return processor;
}

int Computer::getVideo() const
{
	return video;
}

int Computer::getHardDrive() const
{
	return hardDrive;
}

int Computer::getWeight() const
{
	return weight;
}

int Computer::getBatteryLife() const
{
	return batteryLife;
}

double Computer::getPrice() const
{
	return price;
}

int Computer::getQuantity() const
{
	return quantity;
}

void Computer::setQuantity(int quantity)
{
	if (quantity < 0) {
		this->quantity = 0;
		throw std::invalid_argument("Quantity must be positive!");
	}
	else 
		this->quantity = quantity;
}

Computer& Computer::operator+=(int quantity)
{
	if (quantity <= 0)
		throw std::invalid_argument("Quantity must be positive!");
	this->quantity += quantity;

	return *this;
}

Computer& Computer::operator-=(int quantity)
{
	if (quantity <= 0)
		throw std::invalid_argument("Quantity must be positive!");
	if (quantity > this->quantity)
		throw std::invalid_argument("Not enough stock to remove!");

	this->quantity -= quantity;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Computer& computer)
{
	os << "\n---------------------------------------\n";
	os << "---------------------------------------\n";
	os << "ID: " << computer.ID << "\n";
	os << "Brand: " << computer.brand << "\n";
	os << "Processor: " << computer.processor << "\n";
	os << "Video: " << computer.video << "\n";
	os << "Hard Drive: " << computer.hardDrive << "\n";
	os << "Weight: " << computer.weight << "\n";
	os << "Battery Life: " << computer.batteryLife << "\n";
	os << "Price: " << computer.price << "\n";
	os << "Quantity: " << computer.quantity << "\n";
	os << "---------------------------------------\n";
	os << "---------------------------------------\n";

	return os;
}

bool operator==(const Computer& lhs, const Computer& rhs)
{
	if (lhs.batteryLife != rhs.batteryLife) return false;
	if (strcmp(lhs.brand, rhs.brand) != 0) return false;
	if (strcmp(lhs.processor, rhs.processor) != 0) return false;
	if (lhs.video != rhs.video) return false;
	if (lhs.hardDrive != rhs.hardDrive) return false;
	if (lhs.weight != rhs.weight) return false;
	if (lhs.price != rhs.price) return false;

	return true;
}
