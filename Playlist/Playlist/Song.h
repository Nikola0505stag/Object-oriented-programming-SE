#pragma once
#include <fstream>
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)

class Song {
	char* title;
	char* author;
	int duration;

	void free();
	void copyFrom(const Song& other);

public:

	Song();
	Song(const char* title, const char* author, int duration);
	Song(const Song& other);
	Song& operator= (const Song& other);
	~Song();

	void setDuration(int duration);
	void setTitle(const char* title);
	void setAuthor(const char* author);

	const char* getTitle() const;
	const char* getAuthor() const;
	int getDuration() const;

	friend std::ostream& operator<<(std::ostream& os, const Song& song);
	friend std::istream& operator>>(std::istream& is, Song& song);
	friend bool operator==(const Song& song1, const Song& song2);
};

