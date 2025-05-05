#include "DrawCard.h"

DrawCard::DrawCard():UnoCard()
{
	number = 0;
}

DrawCard::DrawCard(int number, Color color):UnoCard(color)
{
	if (number != 2 && number != 4)
		throw std::invalid_argument("Wrong number for draw...");

	this->number = number;
}

DrawCard::DrawCard(int number, int color):UnoCard(color)
{
	if (number != 2 && number != 4)
		throw std::invalid_argument("Wrong number for draw...");

	this->number = number;
}
