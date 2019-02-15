#pragma once
#include <iostream>
#include <string.h>
#include <string>
class Complex {
public:
	Complex(double complex = 0, double real = 0);
	Complex(const Complex &c);
	void printNumber(void);
	Complex add(Complex &c);
	double getReal();
	double getComplex();
	void setReal(double r);
	void setComplex(double c);
	void read(void);
private:
	double real;
	double complex;
};
Complex add(Complex c1, Complex c2);
Complex operator+(const Complex &left, const Complex &right);
Complex operator-(const Complex &left, const Complex &right);
std::istream & operator >> (std::istream &lhs, Complex &rhs);
std::ostream & operator<< (std::ostream &lhs, const Complex &rhs);