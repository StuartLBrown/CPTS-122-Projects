#include <iostream>
#include <string>
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
	Node *getNext(void) const;//constant function
	string getName(void) const;//constant function
	void setName(string &newString);
	void setNext(Node *pNext);
private:
	Node *next;
	string name;
};