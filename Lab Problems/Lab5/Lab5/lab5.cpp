#include "lab5.h"
Complex::Complex(double complex, double real) {
	Complex::complex = complex;
	Complex::real = real;
}
Complex::Complex(const Complex &c) {
	complex = c.complex;
	real = c.real;
}
Complex Complex::add(Complex &c) {
	real += c.getReal();
	complex += c.getComplex();
	return *this;
}
const double Complex::getReal() {
	return real;
}
const double Complex::getComplex() {
	return complex;
}
void Complex::setReal(double r) {
	real = r;
}
void Complex::setComplex(double c) {
	complex = c;
}
void Complex::printNumber(void) {
	std::cout << real << "+" << complex << "i\n";
}
void Complex::read(void) {
	char line[100];
	std::cout << "Enter a complex number in the format (a+bi - no space): ";
	std::cin >> line;
	real = atof(strtok(line, "+"));
	complex = atof(strtok(NULL, "i"));
}
Complex add(Complex c1, Complex c2) {
	return c1.add(c2);
}
Complex operator+(const Complex &left, const Complex &right) {
	Complex c3 = left, c4 = right;
	return add(c3, c4);
}
Complex operator-(const Complex &left , const Complex &right) {
	Complex left1 = left, right1 = right, value;
	value.setComplex(left1.getComplex() - right1.getComplex());
	value.setReal(left1.getReal() - right1.getReal());
	return value;
}
std::istream &operator >> (std::istream &lhs, Complex &rhs) {
	std::string real, imagine;
	lhs >> real;
	rhs.setReal(std::stod(real));
	lhs >> imagine >> imagine;
	rhs.setComplex(std::stod(imagine));
	return lhs;
}
std::ostream &operator<<(std::ostream &lhs, const Complex &rhs) {
	Complex c1 = rhs;
	lhs << c1.getReal()<<"+"<<c1.getComplex()<<"i";
	return lhs;
}