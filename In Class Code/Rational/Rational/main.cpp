// This example will allow us to explore
// classes, data members, member functions,
// constructor, destructors, function overloading,
// operator overloading, etc. We are building
// these ideas around a Rational object

// History: 

#include "Rational.h"

int main(void)
{
	Rational r1(0, 1), r2(5, 2), r3, r4(7);

	r1 = r2.add(r4);

	fstream fstr;
	fstr.open("RNumbers.txt");
	fstr >> r1;
	cout << r1.getNumerator() << " / " << r1.getDenominator() << std::endl;

	return 0;
}