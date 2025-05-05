#pragma once
#include "UnoCard.h"


class DrawCard : public UnoCard
{
	int number;


public:
	DrawCard();
	DrawCard(int number, Color color);
	DrawCard(int number, int color);
};

