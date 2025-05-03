#include "VehicleList.h"

using std::endl;
using std::cin;
using std::cout;

int main() {

	Registration reg("C1234AB"), reg2("ABCDEF");
	cout << (reg != reg2);

	Vehicle veh("C1234AB", "Very cool car very very");
	Vehicle vec(reg2, "NOT VERY COOL CAR NOT VERY");

	vec = veh;
	cin >> vec;
	cout << vec;

	VehicleList v1(10), v2(20);
	v1 += veh;
	v1 += vec;
	return 0;
}