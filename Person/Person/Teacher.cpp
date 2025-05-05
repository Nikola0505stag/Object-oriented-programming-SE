#include "Teacher.h"

void Teacher::copyFrom(const Teacher& other)
{
	subjects = new char[strlen(other.subjects) + 1];
	strcpy(subjects, other.subjects);
}

void Teacher::free()
{
	delete[] subjects;
	subjects = nullptr;
}

void Teacher::moveFrom(Teacher&& other)
{
	subjects = other.subjects;
	other.subjects = nullptr;
}

Teacher::Teacher() : Person()
{
	setSubjects("DEFAULT_SUBJECTS");
}

Teacher::Teacher(const char* subjects, const char* name, size_t age):Person(age,name)
{
	setSubjects(subjects);
}

Teacher::Teacher(const Teacher& other):Person(other)
{
	copyFrom(other);
}

Teacher::Teacher(Teacher&& other) noexcept : Person(std::move(other))
{
	moveFrom(std::move(other));
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other) {
		Person::operator=(other);
		free();
		copyFrom(other);
	}
}

Teacher& Teacher::operator=(Teacher&& other) noexcept
{
	if (this != &other) {
		Person::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}
}

Teacher::~Teacher()
{
	free();
}

void Teacher::setSubjects(const char* subjects)
{
	if (!subjects)
		throw std::invalid_argument("Subjects is nullptr...");
	if (this->subjects == subjects)
		return;

	delete[] this->subjects;
	this->subjects = new char[strlen(subjects) + 1];
	strcpy(this->subjects, subjects);
}

const char* Teacher::getSubjects() const
{
	return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Teacher& teacher)
{
	os << "------------------------------------------\n";
	os << "AGE: " << teacher.getAge() << "\n";
	os << "NAME: " << teacher.getName() << '\n';
	os << "SUBJECTS: " << teacher.getSubjects() << "\n";
	os << "------------------------------------------\n";

	return os;
}

std::istream& operator>>(std::istream& is, Teacher& teacher)
{
	size_t curr;
	is >> curr;
	teacher.setAge(curr); is.ignore();

	char buff[1024];

	is.getline(buff, 1024);

	teacher.setName(buff);

	is.getline(buff, 1024);
	teacher.setSubjects(buff);

	return is;
}
