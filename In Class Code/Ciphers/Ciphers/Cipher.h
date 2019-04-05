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
	string encode(const string &msg, const int key);
	string decode(const string &encmsg, const int key);
private:
	//string msg;
	int key;
};