#include "TimestampWithDescription.h"

using std::endl;
using std::cin;
using std::cout;

int main() {

	
	Timestamp ts(10000);
	ts += 1000;
	cout << ts;

	TimestampWithDescription tw;
	cin >> tw;
	cout << tw;

	return 0;
}