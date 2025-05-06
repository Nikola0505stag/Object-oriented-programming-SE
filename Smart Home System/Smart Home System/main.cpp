#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SmartSpeaker.h"

using std::cin;
using std::cout;
using std::endl;


int main() {

	Device* light = new SmartLight(100,"Nikola Neychev",102.21);
	Device* thermo = new SmartThermostat(20, 22, "Nikola Neychev", 102.21);
	Device* volume = new SmartSpeaker(100, "Nikola Neychev", 121.21);

	volume->printDetails();

	return 0;
}