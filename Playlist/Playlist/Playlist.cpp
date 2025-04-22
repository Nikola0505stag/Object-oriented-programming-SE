#include "Playlist.h"

void Playlist::free()
{
	delete[] songs;

	songs = nullptr;
	capacity = 16;
	size = 0;
}

void Playlist::copyFrom(const Playlist& other)
{
	capacity = other.capacity;
	size = other.size;

	songs = new Song[capacity];

	for (int i = 0; i < size; i++) {
		songs[i] = other.songs[i];
	}
}

void Playlist::resize(int newCapacity)
{
	Song* newSongs = new Song[newCapacity];

	for (int i = 0; i < size; i++) {
		newSongs[i] = songs[i]; // използваме оператора = на Song
	}

	delete[] songs;
	songs = newSongs;
	capacity = newCapacity;
}

Playlist::Playlist() {
	capacity = 16;
	size = 0;
	songs = new Song[capacity];
}

Playlist::Playlist(Song* songs, int size, int capacity)
{
	this->size = size;
	this->capacity = capacity;

	this->songs = new Song[this->capacity];

	for (int i = 0; i < this->size; i++) {
		this->songs[i] = songs[i];
	}
}

Playlist::Playlist(const Playlist& other)
{
	copyFrom(other);
}

Playlist& Playlist::operator=(const Playlist& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Playlist::~Playlist()
{
	free();
}

int Playlist::getSize() const
{
	return size;
}

int Playlist::getCapacity() const
{
	return capacity;
}

int Playlist::getSumDuration() const
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += songs[i].getDuration();
	}
	return sum;
}

Playlist& Playlist::operator+=(const Song& song)
{
	if (size >= capacity) {
		resize(capacity * 2);
	}
	this->songs[size++] = song;

	return *this;
}

Playlist& Playlist::operator-=(const Song& song)
{
	for (int i = 0; i < size; i++) {
		if (songs[i] == song) {
			std::swap(songs[i], songs[size - 1]);
			size--;
			break;
		}
	}
	
	return *this;
}

Playlist& Playlist::operator+=(const Playlist& play)
{
	if (size + play.size >= capacity) {
		resize(capacity + play.capacity);
	}
	for (int i = size; i < play.size; i++) {
		songs[size + i] = play.songs[i];
	}
	size += play.size;

	return *this;
}

void Playlist::saveToFile(std::ofstream& ofs) const
{
	ofs.write((const char*)&capacity, sizeof(capacity));
	ofs.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++) {
		const Song& song = songs[i];

		int titleLen = strlen(song.getTitle()) + 1;
		ofs.write((const char*)&titleLen, sizeof(titleLen));
		ofs.write((const char*)song.getTitle(), titleLen);

		int authorLen = strlen(song.getAuthor()) + 1;
		ofs.write((const char*)(&authorLen), sizeof(authorLen));
		ofs.write((const char*)song.getAuthor(), authorLen);

		int duration = song.getDuration();

		ofs.write((const char*)&duration, sizeof(duration));
	}
}

void Playlist::loadFromFile(std::ifstream& ifs)
{
	ifs.read((char*)&capacity, sizeof(capacity));
	ifs.read((char*)(&size), sizeof(size));

	

	for (int i = 0; i < size; i++) {
		size_t titleLen, authorLen;
		int duration;

		ifs.read((char*)(&titleLen), sizeof(titleLen));
		char* title = new char[titleLen];
		ifs.read((char*)title, titleLen);

		ifs.read((char*)(&authorLen), sizeof(authorLen));
		char* author = new char[authorLen];
		ifs.read((char*)author, authorLen);

		ifs.read((char*)(&duration), sizeof(duration));

		songs[i] = Song(title, author, duration);

		delete[] title;
		delete[] author;
	}

}

std::ostream& operator<<(std::ostream& os, const Playlist& play)
{
	for (int i = 0; i < play.size; i++) {
		os << play.songs[i] << "\n";
	}
	return os;
}

Playlist operator+(const Playlist& pl1, const Playlist& pl2)
{
	Playlist pl(pl1);
	pl += pl2;
	return pl;
}
