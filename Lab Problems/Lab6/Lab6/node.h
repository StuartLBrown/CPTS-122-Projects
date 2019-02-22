#include <iostream>
#include <string>
#pragma once
using std::string;
class Node {
private:
	Node *next;
	string data;
public:
	Node(string newData = "", Node *n = nullptr);
	~Node(void);
	Node *getNext(void);
	string getData(void);
	void setData(string &_data);
	void setNext(Node *node);
};