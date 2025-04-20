#pragma once
#define PAGES_COUNT 30
#include "Webpage.h"

class Browser {
	Webpage pages[PAGES_COUNT];
	int count;

	int findPage(const Webpage& page);

public:
	Browser();
	Browser(const Webpage* pages, int count);

	void addPage(const Webpage& page);
	void removePage(const Webpage& page);
	void addPage(const char* address, const char* ip);
	void removePage(const char* address, const char* ip);

	friend std::ostream& operator<<(std::ostream& os, const Browser& browser);

	Browser& operator+=(const Webpage& page);

	Browser& operator-=(const Webpage& page);


	int getCount() const;
};