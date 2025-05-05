#include "Ticket.h"
#include "StudentTicket.h"

using std::endl;
using std::cin;
using std::cout;

int main() {

	Ticket t1;
	cout << t1;
	cin >> t1;
	cout << t1;


	StudentTicket st1("Name", 10);
	cout << st1;

	return 0;
}