#include "Browser.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

	Webpage w1, w2;
	w1.setAddress("hello.cs");
	w1.setIp("!21l1.ajsd1");

	w2 = w1;

	Webpage w3("1","1");
	
	Webpage pages[3];
	pages[0] = w1;
	pages[1] = w2;
	pages[2] = w3;

	Browser br(pages, 3);
	br.addPage(w1);

	br.removePage(w3);
	br.removePage(w1);
	cout << br << endl<<br.getCount();
	br.addPage(w3);
	cout << br << endl << br.getCount();

	br += w1;
	br += w1;
	br += w1;
	br -= w1;
	br -= w1;
	cout << br;

	return 0;
}