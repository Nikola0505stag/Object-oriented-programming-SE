#include "Song.h"

void Song::free()
{
	delete[] title;
	delete[] author;

	title = nullptr;
	author = nullptr;
	duration = 0;
}

void Song::copyFrom(const Song& other)
{
	title = new char[strlen(other.title) + 1];
	author = new char[strlen(other.author) + 1];
	
	duration = other.duration;
	strcpy(title, other.title);
	strcpy(author, other.author);
}

Song::Song()
{
	duration = 0;
	setTitle(nullptr);
	setAuthor(nullptr);
}

Song::Song(const char* title, const char* author, int duration)
{
	setTitle(title);
	setAuthor(author);
	setDuration(duration);
}

Song::Song(const Song& other)
{
	copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Song::~Song()
{
	free();
}

void Song::setDuration(int duration)
{
	if (duration > 0)
		this->duration = duration;
	else
		this->duration = -1; // Wrong duration
}
void Song::setTitle(const char* title)
{
	if(title != nullptr)
		delete[] this->title;

	if (!title) {
		this->title = new char[strlen("DEFAULT_TITLE") + 1];
		strcpy(this->title, "DEFAULT_TITLE");
		return;
	}

	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Song::setAuthor(const char* author)
{
	if(author!=nullptr)
		delete[] this->author;

	if (!author) {
		this->author = new char[strlen("DEFAULT_AUTHOR") + 1];
		strcpy(this->author, "DEFAULT_AUTHOR");
		return;
	}
	
	this->author = new char[strlen(author) + 1];
	strcpy(this->author, author);
}

const char* Song::getTitle() const
{
	return title;
}

const char* Song::getAuthor() const
{
	return author;
}

int Song::getDuration() const
{
	return duration;
}

std::ostream& operator<<(std::ostream& os, const Song& song)
{
	os << song.title << "\t" << song.author << "\t" << song.duration;
	return os;
}

std::istream& operator>>(std::istream& is, Song& song)
{
	char buff[1000];

	is.getline(buff, 1000);
	song.title = new char[strlen(buff) + 1];
	strcpy(song.title, buff);

	is.getline(buff, 1000);
	song.author = new char[strlen(buff) + 1];
	strcpy(song.author, buff);

	is >> song.duration;

	return is;
}

bool operator==(const Song& song1, const Song& song2)
{
	if (strcmp(song1.author, song2.author) == 0 && strcmp(song1.title, song2.title) == 0 && song1.duration == song2.duration)
		return true;
	return false;
}
