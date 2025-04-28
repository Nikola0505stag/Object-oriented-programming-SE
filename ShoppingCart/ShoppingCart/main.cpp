#include "ShoppingCart.h"

using std::endl;
using std::cin;
using std::cout;

int main() {

	Item i1;
	cin >> i1;
	cout << i1;

	std::ofstream ofs("item1.bin", std::ios::binary);

	i1.writeInFile(ofs);

	ofs.close();


	ShoppingCart cart;

	cin >> cart;

	cart += i1;
	cart += i1;
	cart += i1;
	//cout << cart.getSize() << " " << cart.getCapacity();

	cout << endl << cart;

	return 0;
}