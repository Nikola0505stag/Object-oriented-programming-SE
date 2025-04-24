#include "Book.h"

void Book::copyFrom(const Book& other)
{
	ID = other.ID;
	year = other.year;
	price = other.price;

	title = new char[strlen(other.title) + 1];
	author = new char[strlen(other.author) + 1];

	strcpy(title, other.title);
	strcpy(author, other.author);
}

void Book::free()
{
	delete[] title;
	delete[] author;

	ID = 0;
	year = 0;
	price = 0.0;
	title = nullptr;
	author = nullptr;
}

Book::Book()
{
	setID(0);
	setTitle(nullptr);
	setAuthor(nullptr);
	setPrice(0.0);
	setYear(0);
}

Book::Book(int ID, const char* title, const char* author, int year, double price)
{
	setID(ID);
	setTitle(title);
	setAuthor(author);
	setYear(year);
	setPrice(price);
}

Book::Book(const Book& other)
{
	copyFrom(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Book::~Book()
{
	free();
}

void Book::setID(int ID)
{
	if (ID <= 0)
		this->ID = 0;
	else
		this->ID = ID;
}

void Book::setTitle(const char* title)
{
	delete[] this->title;

	if (!title) {
		this->title = new char[strlen("DEFAULT_TITLE") + 1];
		strcpy(this->title, "DEFAULT_TITLE");
		return;
	}
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Book::setAuthor(const char* author)
{
	delete[] this->author;

	if (!author) {
		this->author = new char[strlen("DEFAULT_AUTHOR") + 1];
		strcpy(this->author, "DEFAULT_AUTHOR");
		return;
	}
	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}

void Book::setYear(int year)
{
	this->year = year;
}

void Book::setPrice(double price)
{
	if (price <= 0)
		this->price = 0.0;
	else
		this->price = price;
}

int Book::getID() const
{
	return ID;
}

const char* Book::getTitle() const
{
	return title;
}

const char* Book::getAuthor() const
{
	return author;
}

int Book::getYear() const
{
	return year;
}

double Book::getPrice() const
{
	return price;
}

void Book::writeInFile(std::ofstream& ofs) const
{

	ofs.write((const char*)&ID, sizeof(ID));
	
	int titleLen = strlen(title) + 1;

	ofs.write((const char*)&titleLen, sizeof(titleLen));
	ofs.write((const char*)title, titleLen);

	int authorLen = strlen(author) + 1;
	
	ofs.write((const char*)&authorLen, sizeof(authorLen));
	ofs.write((const char*)author, authorLen);

	ofs.write((const char*)&year, sizeof(year));
	ofs.write((const char*)&price, sizeof(price));

}

void Book::readFromFile(std::ifstream& ifs)
{
	free();

	ifs.read((char*)&ID, sizeof(ID));

	int titleLen;

	ifs.read((char*)&titleLen, sizeof(titleLen));

	title = new char[titleLen];

	ifs.read((char*)title, titleLen);

	int authorLen;

	ifs.read((char*)&authorLen, sizeof(authorLen));

	author = new char[authorLen];

	ifs.read((char*)author, authorLen);

	ifs.read((char*)&year, sizeof(year));
	ifs.read((char*)&price, sizeof(price));
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.ID << "\t" << book.title << "\t" << book.author << "\t" << book.year << "\t" << book.price;
	return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
	book.free();
	
	is >> book.ID;
	is.ignore();

	char buff[1024];

	is.getline(buff, 1024);

	book.title = new char[strlen(buff) + 1];
	strcpy(book.title, buff);

	is.getline(buff, 1024);
	book.author = new char[strlen(buff) + 1];
	strcpy(book.author, buff);

	is >> book.year;
	is >> book.price;

	return is;
}
