#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable:4996)

class Person
{

	size_t age;
	char* name;

	void copyFrom(const Person& other);
	void free();
	void moveFrom(Person&& other);

public:
	Person();
	Person(size_t age, const char* name);
	Person(const Person& other);
	Person(Person&& other) noexcept;
	Person& operator=(const Person& other);
	Person& operator=(Person&& other) noexcept;
	~Person();

	void setAge(size_t age);
	void setName(const char* name);

	size_t getAge() const;
	const char* getName() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);
	friend std::istream& operator>>(std::istream& is, Person& person);
	
};

