#include <iostream>
#pragma once
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node {
public:
	Node(const string &s);
	Node(const Node &n);
	~Node(void);
	Node *getNext(void);
	string getName(void);
private:
	Node *next;
	string name;
};