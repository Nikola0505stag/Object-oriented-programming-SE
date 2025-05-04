#pragma once
#include "Person.h"

class Student : public Person
{
	char* fn;

	void copyFrom(const Student& other);
	void free();
	void moveFrom(Student&& other);

public:
	Student();
	Student(const char* fn, const char* name, size_t age);
	Student(const Student& other);
	Student(Student&& other);
	Student& operator=(const Student& other);
	Student& operator=(Student&& other);
	~Student();

	const char* getFn() const;
	void setFn(const char* fn);

	friend std::ostream& operator<<(std::ostream& os, const Student& student);
	friend std::istream& operator>>(std::istream& is, Student& student);

};

