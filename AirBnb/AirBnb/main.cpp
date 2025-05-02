#include "AirBnb.h"

using std::endl;
using std::cin;
using std::cout;

int main() {

	Accommodation ac;

	Accommodation ac1(ac);
	Accommodation ac2;
	ac2 = ac1;
	Accommodation a1, a2, a3, a4, a5;
	a5 = a1;

	cin >> a5; cout << a5 << endl;
	a5.saveReservation(10);

	AirBnb air;

	air += a5;

	cout << air;

	air.reserve(25, 101);

}