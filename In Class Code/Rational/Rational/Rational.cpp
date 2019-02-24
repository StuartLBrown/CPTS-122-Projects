// We will place the definitions for only
// Rational's operations in this file

#include "Rational.h"

//Rational::Rational()
//{
//	mNumerator = 0;
//	mDenominator = 1;
//}
//
//Rational::Rational(int newNumerator, int newDenominator)
//{
//	mNumerator = newNumerator;
//	mDenominator = newDenominator;
//}

Rational::Rational(int newNumerator, int newDenominator){
	mNumerator = newNumerator;

	// validate the denominator
	if (newDenominator != 0)
		mDenominator = newDenominator;
	else
		mDenominator = 1;
}

int Rational::getNumerator() const{
	return mNumerator;
}

int Rational::getDenominator() const{
	return mDenominator;
}


void Rational::setNumerator(int const newNumerator){
	mNumerator = newNumerator;
}

void Rational::setDenominator(int const newDenominator){
	// validate the denominator
	if (newDenominator != 0)
		mDenominator = newDenominator;
}

// implicitly called when passing-by-value
Rational::Rational(const Rational &copy){
	//mNumerator = copy.mNumerator; // could also work
	setNumerator(copy.getNumerator());
	setDenominator(copy.getDenominator());
}

Rational Rational::add(const Rational &rhs){
	Rational result;

	result.setDenominator(rhs.getDenominator() *
		getDenominator());
	result.setNumerator(rhs.getNumerator() * getDenominator() +
		getNumerator()*rhs.getDenominator());

	return result;
}

Rational::~Rational(){
	//cout << "Inside destructor for Rational" << std::endl;
}

Rational & Rational::operator= (const Rational &rhs){
	setNumerator(rhs.getNumerator());
	setDenominator(rhs.getDenominator());
	return (*this);
}

fstream &operator >> (fstream &lhs, Rational &rhs) {
	int temp = 0, temp2=0;
	char slash = '\0';
	lhs >> temp >> slash >>temp2;
	rhs.setDenominator(temp2);
	rhs.setNumerator(temp);
	return lhs;
}