#include "Tests.h"
int main(void) {
	srand(unsigned int(time(NULL)));
	Tests t;
	/*t.testEnqueueEmpty();
	t.testEnqueueOneNode();
	t.testDequeueOneNode();
	t.testDeqeueTwoNodes();*/
	t.test24Hours();
	/*int mins = 0;
	while (mins <= 0) {
		cout << "enter a time for the simulation to run (in minutes): ";
		cin >> mins;
	}
	runsimulation(mins);*/
	return 0;
}