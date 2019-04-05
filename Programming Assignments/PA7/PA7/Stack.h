#pragma once
#include <string>
#include <iostream>
using std::string;
class Stack {
private:
	int size, maxSize;
	string *top;
public:
	Stack(int size = 0);
	//deep copy constructor
	Stack(const Stack &_s);
	void push(string &newItem);
	string pop();
	string peek();
	bool isEmpty();
};
Stack::Stack(int _size) {
	size = _size;
	maxSize = 200;
	top = new string[200];
}
void Stack::push(string &newItem) {
	if (size >= maxSize)
		std::cout << "Max size of stack reached" << std::endl;
	else {
		top[size] = newItem;
		size++;
	}
}
string Stack::pop() {
	if (isEmpty())
		return "";
	string item = top[size - 1];
	size--;
	return item;
}
string Stack::peek() {
	return top[size - 1];
}
bool Stack::isEmpty() {
	return top[0] == "" || top == nullptr || size==0;
}
Stack::Stack(const Stack &_s) {
	top = new string[_s.maxSize];
	for (int i = 0; i < _s.size; i++) {
		top[i] = *(new string(_s.top[i]));
	}
	size = _s.size;
	maxSize = _s.maxSize;
}