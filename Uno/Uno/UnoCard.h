#pragma once
#include <iostream>
#include <fstream>


enum Color {
	Red = 0,
	Green = 1,
	Blue = 2,
	Yellow = 3,
	DEFAULT_COLOR = 4
};

class UnoCard
{
	Color color;

public:

	UnoCard();
	UnoCard(Color color);
	UnoCard(int number);
};

