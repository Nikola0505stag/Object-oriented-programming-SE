#include "ComputerStore.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

	Computer c("MAC","Intel 550",10,10,10,10,10.2,10);

	c.setQuantity(100);

	cout << c;

	ComputerStore cs("Nikola");

	cs += c;
	cs += c;

	cout << cs;

	return 0;
}