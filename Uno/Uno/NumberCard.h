#pragma once
#include "UnoCard.h"

class NumberCard : public UnoCard
{
	int number;

public:
	NumberCard();
	NumberCard(int number, Color color);
	NumberCard(int number, int color);
};

