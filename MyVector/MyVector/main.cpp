#include "MyVector.hpp"

using namespace std;

int main() {

	MyVector <int> vector;

	vector.push_back(10);
	vector.push_back(11);

	cout << vector.getCapacity() << "\t" << vector.getSize();
	cout << endl;
	cout << vector;
	
	return 0;
}