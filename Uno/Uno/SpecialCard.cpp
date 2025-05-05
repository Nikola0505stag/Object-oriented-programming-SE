#include "SpecialCard.h"

SpecialCard::SpecialCard() : UnoCard()
{
	special = Special::DEFAULT_SPECIAL;
}

SpecialCard::SpecialCard(Special special, Color color) : UnoCard(color)
{
	this->special = special;
}

SpecialCard::SpecialCard(Special special, int color):UnoCard(color)
{
	if (special < 0 || special > 2)
		throw std::invalid_argument("Wrong number for color...");

	this->special = special;
}
