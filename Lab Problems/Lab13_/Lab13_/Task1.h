#include <iostream>
using std::cout;
using std::endl;
class Base {
public:
	virtual void testFunction() { cout << "Base class" << endl; }
};
class Derived : public Base {
public:
	void testFunction() { cout << "Derived class" << endl; }
};