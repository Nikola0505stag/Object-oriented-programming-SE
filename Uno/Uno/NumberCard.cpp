#include "NumberCard.h"

NumberCard::NumberCard():UnoCard()
{
	number = 0;
}

NumberCard::NumberCard(int number, Color color):UnoCard(color)
{
	if (number < 0 || number > 9)
		throw std::invalid_argument("Wrong number for card...");
	this->number = number;
}

NumberCard::NumberCard(int number, int color) :UnoCard(color)
{
	if (number < 0 || number > 9)
		throw std::invalid_argument("Wrong number for card...");

	this->number = number;
}
