#include "Browser.h"

int Browser::findPage(const Webpage& page)
{
	for (int i = 0; i < count; i++) {
		if (strcmp(page.getAddress(), pages[i].getAddress()) == 0 &&
			strcmp(page.getIp(), pages[i].getIp()) == 0)
			return i;
	}
	return -1;

}

Browser::Browser()
{
	count = 0;
}

Browser::Browser(const Webpage* pages, int count)
{
	this->count = count;

	for (int i = 0; i < this->count; i++) {
		this->pages[i] = pages[i];
	}
}

void Browser::addPage(const Webpage& page)
{
	if (count < PAGES_COUNT) {
		pages[count++] = page;
	}
}

void Browser::removePage(const Webpage& page)
{
	int curr = findPage(page);

	std::swap(pages[curr], pages[count - 1]);
	count--;
}

void Browser::addPage(const char* address, const char* ip)
{
	Webpage curr(address, ip);
	addPage(curr);
}

void Browser::removePage(const char* address, const char* ip)
{
	Webpage curr(address, ip);
	removePage(curr);
}

Browser& Browser::operator+=(const Webpage& page)
{
	addPage(page);

	return *this;
}

Browser& Browser::operator-=(const Webpage& page)
{
	removePage(page);
	
	return *this;
}

int Browser::getCount() const
{
	return count;
}

std::ostream& operator<<(std::ostream& os, const Browser& browser)
{
	for (int i = 0; i < browser.count; i++) {
		os << browser.pages[i] << "\n";
	}
	return os;
}
