#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning(disable:4996)

class Book {
	int ID;
	char* title;
	char* author;
	int year;
	double price;

	void copyFrom(const Book& other);
	void free();


public:
	Book();
	Book(int ID, const char* title, const char* author, int year, double price);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	void setID(int ID);
	void setTitle(const char* title);
	void setAuthor(const char* author);
	void setYear(int year);
	void setPrice(double price);

	int getID() const;
	const char* getTitle() const;
	const char* getAuthor() const;
	int getYear() const;
	double getPrice() const;

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
	friend std::istream& operator>>(std::istream& is, Book& book);

	void writeInFile(std::ofstream& ofs) const;
	void readFromFile(std::ifstream& ifs);

};