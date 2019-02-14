#include "rectangle.h"
int main(void) {
	Rectangle r(5, 8), r2(3), r3 = r2;
	r2.printRectangle();
	printRectangle(r3);
	int n1 = 10, &n2 = n1;//& - alias operator (another name for the variable)
	//std::cout << n1 << "\n" << n2 << "\n";
	//std::cout << "length: " << r.getLength() << "\nwidth: " << r.getWidth() << "\n";
	return 0;
}