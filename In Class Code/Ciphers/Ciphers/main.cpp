// This example is intended to provide a quick
// review of inheritance and polymorphism. It works
// with ciphers.

#include "Caesar.h"

int main(void)
{
	Cipher *c = new Caesar(10);
	string msg = "test";
	std::cout<<c->decode(c->encode(msg))<<std::endl;
	return 0;
}