//have to use .cpp file extension

//similar to stdio.h
#include <iostream>
int add(int n1, int n2);
double add(double n1, double n2);

int main(void) {
	//standard library (namespace, common location for many functions)
	std::cout << "Hello World" << std::endl;
	//<< stream insertion operator | cout - console out
	int temp = 42;
	//don't have to use % whatever with cout - just have to use << - std::endl is essentially /n
	std::cout << "Number: " << temp << std::endl;

	std::cout << "Enter a number: ";
	//>> stream extraction operator - cin is scanf - don't have to use address of variable - only name
	std::cin >> temp;
	std::cout << temp << std::endl;
	
	return 0;
}
int add(int n1, int n2) {
	return n1 + n2;
}
double add(double n1, double n2) {
	return n1 + n2;
}