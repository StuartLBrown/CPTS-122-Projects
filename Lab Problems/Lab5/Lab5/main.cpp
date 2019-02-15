#include "lab5.h"
int main(void) {
	Complex c1(3.5, 2), c2(5.5, 7), c3;
	c3 = c1.add(c2);  // member add () function
	c3 = add(c1, c2); // non-member add () function
	c3 = c1 + c2;       // overloaded + operator
	std::cout << "Enter a complex number in the format (a+bi - no spaces): ";
	std::cin >> c3;
	std::cout << c3;
	return 0;
}