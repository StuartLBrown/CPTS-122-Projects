// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class
// Inheritance starter code! Not yet complete!
#include "Manager.h"

void printPay(Employee &e) {
	cout << "Pay Rate: " << e.calculatePay() << endl;
}

int main(void)
{
	Manager m("temp", 10, 40, false);
	printPay(m);
	return 0;
}