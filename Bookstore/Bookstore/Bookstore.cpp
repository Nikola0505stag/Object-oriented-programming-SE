#include "Bookstore.h"

void Bookstore::resize(int newCapacity)
{
	Book* newBooks = new Book[newCapacity];

	for (int i = 0; i < size; i++) {
		newBooks[i] = books[i]; 
	}

	delete[] books;

	books = newBooks;
	capacity = newCapacity;
}

void Bookstore::copyFrom(const Bookstore& other)
{
	capacity = other.capacity;
	size = other.size;

	books = new Book[capacity];

	for (int i = 0; i < size; i++) {
		books[i] = other.books[i];
	}

	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}
void Bookstore::free()
{
	if (name) {
		delete[] name;  // Освобождаваме паметта за името
		name = nullptr;
	}
	if (books) {
		delete[] books;  // Освобождаваме паметта за масива с книги
		books = nullptr;
	}

	size = 0;
	capacity = 0;
}

Bookstore::Bookstore()
{
	setName(nullptr);

	size = 0;
	capacity = 16;
	books = new Book[capacity];
}

Bookstore::Bookstore(const Book* books, const char* name, int size, int capacity)
{
	setName(name);
	this->size = size;
	this->capacity = capacity;

	this->books = new Book[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->books[i] = books[i];
	}
}

Bookstore::Bookstore(const Bookstore& other)
{
	copyFrom(other);
}

Bookstore& Bookstore::operator=(const Bookstore& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Bookstore::~Bookstore()
{
	free();
}

void Bookstore::setName(const char* name)
{
	delete[] this->name;

	if (!name) {
		this->name = new char[strlen("DEFAULT_NAME") + 1];
		strcpy(this->name, "DEFAULT_NAME");
		return;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

const char* Bookstore::getName() const
{
	return name;
}

int Bookstore::getSize() const
{
	return size;
}

int Bookstore::getCapacity() const
{
	return capacity;
}

Bookstore& Bookstore::operator+=(const Book& book)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}

	books[size++] = book;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bookstore& bookstore)
{
	os << bookstore.name << ":";
	os << "---------------------------------------------";
	os << std::endl;

	for (int i = 0; i < bookstore.size; i++) {
		os << bookstore.books[i] << std::endl;
	}

	os << "---------------------------------------------\n";
	os << "---------------------------------------------\n\n";
	return os;
}
