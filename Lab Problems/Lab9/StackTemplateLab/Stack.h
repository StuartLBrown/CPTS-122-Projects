// This file contains a stack class template. The underlying data structure for the 
// stack is an array allocated from the heap.

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem); 
	bool pop(T &poppedItem);
	bool peek(T &item);
	int getSize();

	bool isEmpty();

	friend int postfixEval(string expression);
	friend string convertInToPost(string expression);
	//returns true if o1 has higher precedence or equal precedence to o2, false otherwise
	friend bool checkPrecedence(char o1, char o2);

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T *mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T &newItem)
{
	if (mSize >= mMaxSize)
		return false;
	*(mTop+mSize) = *(new T(newItem));
	mSize++;
	return true;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	if (isEmpty())
		return false;
	poppedItem = mTop[mSize - 1];
	mSize--;
	return true;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
bool Stack<T>::peek(T &item)
{
	if(isEmpty())
		return false;
	item = *(mTop + mSize - 1);
	return true;
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	return mTop == nullptr||mSize==0;
}

template <class T>
int Stack<T>::getSize() {
	return mSize;
}

int postfixEval(string expression) {
	Stack<int> S;
	if (expression == "") {
		cout << "String is malformed" << endl;
		return 0;
	}
	int value = 0;
	for (int i = 0; i < expression.length(); i++) {
		if (expression.at(i) == '\0' || expression.at(i) == '\n')
			return value;
		char c = expression.at(i);
		if (c == ' ')
			c = ' ';
		else if (c == '=') {
			if (S.isEmpty()) {
				cout << "String is malformed, equals sign with an empty stack" << endl;
				return value;
			}
			else if (S.getSize() > 1) {
				cout << "String is malformed, equals sign with more than one element in the stack" << endl;
				return value;
			}
			else {
				int temp;
				S.pop(temp);
				return temp;
			}
		}
		else if (c >= '0'&&c <= '9') {
			int temp = (int)c - '0';
			S.push(temp);
		}
		else {
			if (S.getSize() < 2) {
				cout << "String is malformed, operator with less than 2 elements on the stack" << endl;
				return value;
			}
			else {
				int s1 = 0, s2 = 0;
				S.pop(s2);
				S.pop(s1);
				if (c == '*')
					value = s1*s2;
				else if (c == '+')
					value = s1 + s2;
				else if (c == '-')
					value = s1 - s2;
				else if (c == '/')
					value = s1 / s2;
				else if (c == '%')
					value = s1%s2;
				else if (c == '^')
					value = pow(s1, s2);
				else {
					cout << "Invalid operator" << endl;
					return value;
				}
				S.push(value);
				cout << value << endl;
			}
		}
	}
	return value;
}

string convertInToPost(string expression) {
	if (expression == "")
		return "";
	Stack<char> S;
	string exp = "";
	for (int i = 0; i < expression.size(); i++) {
		char c = expression.at(i);
		c = tolower(c);
		if (c == ' ')
			c = ' ';
		else if ((c >= '0'&&c <= '9')||(c>='a'&&c<='z'))
			exp.append(1,c);
		else if (c == '(')
			S.push(c);
		else if (c == ')') {
			while (!S.isEmpty()) {
				S.pop(c);
				if (c == '(')
					break;
				else
					exp.append(1,c);
			}
		}
		else {
			if (S.isEmpty())
				S.push(c);
			else {
				while (!S.isEmpty()) {
					char temp;
					S.peek(temp);
					if (checkPrecedence(temp, c)) {
						S.pop(temp);
						exp.append(1,temp);
					}
					else
						break;
				}
				S.push(c);
			}
		}	
	}
	while (!S.isEmpty()) {
		char temp;
		S.pop(temp);
		exp.append(1, temp);
	}
	return exp;
}

bool checkPrecedence(char o1, char o2) {
	if (o1 == '(' || o2 == '(')
		return false;
	if (o1 == '^')
		return true;
	else if (o1 == '*' || o1 == '/') {
		if (o2 == '^')
			return false;
		return true;
	}
	else {
		if (o2 == '+' || o2 == '-')
			return true;
		return false;
	}
}