#pragma once
#include "Person.h"

class Teacher : public Person
{
	char* subjects;

	void copyFrom(const Teacher& other);
	void free();
	void moveFrom(Teacher&& other);

public:
	Teacher();
	Teacher(const char* subjects, const char* name, size_t age);
	Teacher(const Teacher& other); 
	Teacher(Teacher&& other) noexcept;
	Teacher& operator=(const Teacher& other);
	Teacher& operator=(Teacher&& other) noexcept;
	~Teacher();

	void setSubjects(const char* subjects);
	const char* getSubjects() const;

	friend std::ostream& operator<<(std::ostream& os, const Teacher& teacher);
	friend std::istream& operator>>(std::istream& is, Teacher& teacher);
};

