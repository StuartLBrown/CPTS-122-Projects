#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

class Cipher abstract// make Cipher an abstract class; it's not intended to instantiate a general Cipher object
{
public:
	virtual string encode(const string &msg) = 0;//=0 means pure virtual function
	virtual string decode(const string &encmsg) = 0;
private:
	//string msg;
	//int key;
};