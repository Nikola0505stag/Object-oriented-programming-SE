#include "Triangle.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
	Shape** tr = new Shape * [4];
	tr[0] = new Triangle(1,10,1,10,1,10);

	cout << tr[0]->getArea();


	return 0;
}