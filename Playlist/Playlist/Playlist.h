#pragma once
#include "Song.h"

class Playlist {
	Song* songs;
	int size;
	int capacity;

	void free();
	void copyFrom(const Playlist& other);
	void resize(int newCapacity);

public:
	Playlist();
	Playlist(Song* songs, int size, int capacity);
	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);
	~Playlist();

	int getSize() const;
	int getCapacity() const;
	int getSumDuration() const;
	
	Playlist& operator+=(const Song& song);
	Playlist& operator-=(const Song& song);
	Playlist& operator+=(const Playlist& play);

	friend std::ostream& operator<<(std::ostream& os, const Playlist& play);

	void saveToFile(std::ofstream& ofs) const;
	void loadFromFile(std::ifstream& ifs);

};
Playlist operator+(const Playlist& pl1, const Playlist& pl2);
