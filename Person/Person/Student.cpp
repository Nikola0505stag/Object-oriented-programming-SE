#include "Student.h"

void Student::copyFrom(const Student& other)
{
	fn = new char[strlen(other.fn) + 1];
	strcpy(fn, other.fn);
}

void Student::free()
{
	delete[] fn;
	fn = nullptr;
}

void Student::moveFrom(Student&& other)
{
	fn = other.fn;
	other.fn = nullptr;
}

Student::Student():Person()
{
	setFn("DEFAULT_FN");
}

Student::Student(const char* fn, const char* name, size_t age):Person(age,name)
{
	setFn(fn);
}

Student::Student(const Student& other) :Person(other)
{
	copyFrom(other);
}

Student::Student(Student&& other):Person(std::move(other))
{
	moveFrom(std::move(other));
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Student& Student::operator=(Student&& other)
{
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Student::~Student()
{
	free();
}

const char* Student::getFn() const
{
	return fn;
}

void Student::setFn(const char* fn)
{
	if (!fn)
		throw std::invalid_argument("Fn is nullptr...");
	if (this->fn == fn)
		return;

	delete[] this->fn;

	this->fn = new char[strlen(fn) + 1];
	strcpy(this->fn, fn);
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
	os << "------------------------------------------\n";
	os << "AGE: " << student.getAge() << "\n";
	os << "NAME: " << student.getName() << '\n';
	os << "FN: " << student.getFn() << "\n";
	os << "------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Student& student)
{
	size_t curr;
	is >> curr;
	student.setAge(curr); is.ignore();

	char buff[1024];

	is.getline(buff, 1024);

	student.setName(buff);

	is >> buff;
	student.setFn(buff);

	return is;
}
