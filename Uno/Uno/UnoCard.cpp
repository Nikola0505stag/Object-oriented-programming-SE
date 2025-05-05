#include "UnoCard.h"

UnoCard::UnoCard()
{
	color = Color::DEFAULT_COLOR;
}

UnoCard::UnoCard(Color color)
{
	this->color = color;
}

UnoCard::UnoCard(int number)
{
	if (number > 4 || number < 0)
		throw std::invalid_argument("Wrong color index...");

	color = (Color)number;
}
