#include <stdexcept>//runtime error
#include <iostream>
using std::cout;
using std::runtime_error;
class DivideByZeroException : public runtime_error{
public:
	DivideByZeroException() : runtime_error("Dividing by Zero") {}
	~DivideByZeroException() { cout << "Inside destrutor" << std::endl; }
};