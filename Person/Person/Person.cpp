#include "Person.h"

void Person::copyFrom(const Person& other)
{
	age = other.age;
	
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

void Person::free()
{
	delete[] name;
	name = nullptr;
	age = 0;
}

void Person::moveFrom(Person&& other)
{
	age = other.age;
	name = other.name;
	other.name = nullptr;
	other.age = 0;
}

Person::Person():age(0)
{
	setName("DEFAULT_NAME");
}

Person::Person(size_t age, const char* name)
{

	setAge(age);
	setName(name);

}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person::Person(Person&& other) noexcept
{
	moveFrom(std::move(other));
}

Person& Person::operator=(const Person& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Person& Person::operator=(Person&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Person::~Person()
{
	free();
}

void Person::setAge(size_t age)
{
	if (age > 0) 
		this->age = age;
	else
		throw std::invalid_argument("Age must be greater than 0.");
}

void Person::setName(const char* name)
{
	if (!name)
		throw std::invalid_argument("Name = nullptr...");
	if (this->name == name)
		return;

	delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

size_t Person::getAge() const
{
	return age;
}

const char* Person::getName() const
{
	return name;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << "------------------------------------------\n";
	os << "AGE: " << person.age << "\n";
	os << "NAME: " << person.name << '\n';
	os << "------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Person& person)
{
	is >> person.age; is.ignore();

	char buff[1024];

	is.getline(buff, 1024);

	person.setName(buff);

	return is;
}
