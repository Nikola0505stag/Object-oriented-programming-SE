#pragma once
#include "UnoCard.h"


enum Special {
	Skip = 0,
	Reverse = 1,
	DEFAULT_SPECIAL = 2
};

class SpecialCard : public UnoCard
{
	Special special;

public:
	SpecialCard();
	SpecialCard(Special special, Color color);
	SpecialCard(Special special, int color);
};

