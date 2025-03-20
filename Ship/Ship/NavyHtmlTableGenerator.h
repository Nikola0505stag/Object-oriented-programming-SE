#pragma once
#include "Navy.h"
#define MAX_FILE_NAME 128


class NavyHtmlTableGenerator {

	Navy navy;
	char fileName[MAX_FILE_NAME];


	void saveToFile()const;

public:

	NavyHtmlTableGenerator(const Navy& , const char*);

};
