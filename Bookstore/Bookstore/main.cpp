#include "Bookstore.h"

using std::cin;
using std::cout;
using std::endl;

int main() {

	Book b3;
	cin >> b3;

	std::ofstream ofs("file.bin", std::ios::binary);

	b3.writeInFile(ofs);

	ofs.close();

	Book b2;

	std::ifstream ifs("file.bin", std::ios::binary);

	b2.readFromFile(ifs);

	ifs.close();

	cout << b2;

	Bookstore bookstore;
	bookstore += b3;
	bookstore += b2;

	cout << bookstore;

	return 0;
}