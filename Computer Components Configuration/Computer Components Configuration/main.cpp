#include "CPU.h"
#include "Memory.h"
#include <iostream>
#include "Configuration.h"

int main() {

	Component** cp = new Component *[2];
	cp[0] = new CPU();
	cp[1] = new Memory();

	Configuration cn;
	cn.addItem(*cp[0]);
	cn.addItem(*cp[1]);
	cn.printConfiguration();

	return 0;
}