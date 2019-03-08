#include <iostream>
#include <string>
#pragma once
using std::string;
using std::ostream;
template <class T>
class Node {
private:
	Node<T> *left;
	Node<T> *right;
	T *data;
public:
	Node<T>(T *_data=nullptr) {
		this->data = _data;
		right = left = nullptr;
	}
	Node<T>(Node<T> &copy) {
		this->data = new T;
		*this->data = *copy->data;
		this->left = copy->left;
		this->right = copy->right;
	}
	~Node<T>() {
		delete left;
		delete right;
		delete data;
	}
	Node<T> *&getLeft(void) {
		return left;
	}
	Node<T> *&getRight(void) {
		return right;
	}
	T getData(void) {
		return *this->data;
	}
	void setRight(Node<T> *_right) {
		this->right = _right;
	}
	void setLeft(Node<T> *_left) {
		this->left = _left;
	}
	void setData(T &_data) {
		this->data = new T(data);
	}
};
ostream &operator<<(ostream &lhs, Node<string> *rhs) {
	lhs << rhs->getData()<<std::endl;
	return lhs;
}
