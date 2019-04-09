#pragma once

#include "Cipher.h"

// Concrete class
class Caesar:public Cipher
{
public:
	Caesar(int _key = 0) {
		key = _key;
	}

	string encode(const string &msg) {
		string temp = msg;
		for (int i = 0; i < temp.size(); i++)
			temp[i] += key;
		return temp;
	}

	string decode(const string &encmsg) {
		string temp = encmsg;
		for (int i = 0; i < temp.size(); i++)
			temp[i] -= key;
		return temp;
	}

	void setKey(int newKey) { key = newKey; }

private:
	int key;
};