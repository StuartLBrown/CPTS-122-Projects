#include <iostream>
#include <string>
#include <fstream>
#pragma once
using std::string;
using std::ostream;
using std::endl;
template <class T, class S>
class BSTNode {
private:
	BSTNode<T,S> *right, *left;
	T data1;
	S data2;
public:
	//standard constructor
	BSTNode(T _chr, S _morse);
	//setters
	void setData1(T data);
	void setData2(S data);
	void setRight(BSTNode<T,S> *_right);
	void setLeft(BSTNode<T,S> *_left);
	//getters
	T getData1();
	S getData2();
	BSTNode<T,S> *getRight();
	BSTNode<T,S> *getLeft();
};
//ostream &operator<<(ostream &lhs, BSTNode<char, string> *rhs);

//standard constructor
template<class T,class S>
BSTNode<T,S>::BSTNode(T _data1, S _data2) {
	this->data1 = _data1;
	this->data2 = _data2;
	this->left = this->right = nullptr;
}
//setters
template<class T, class S>
void BSTNode<T, S>::setData1(T data) {
	this->data1 = data;
}
template<class T, class S>
void BSTNode<T, S>::setData2(S data) {
	this->data2 = data;
}
template<class T, class S>
void BSTNode<T, S>::setRight(BSTNode<T, S> *_right) {
	this->right = right;
}
template<class T, class S>
void BSTNode<T, S>::setLeft(BSTNode<T, S> *_left) {
	this->left = left;
}
//getters
template<class T, class S>
T BSTNode<T, S>::getData1() {
	return this->data1;
}
template<class T, class S>
S BSTNode<T, S>::getData2() {
	return this->data2;
}
template<class T, class S>
BSTNode<T, S> *BSTNode<T, S>::getRight() {
	return this->right;
}
template<class T, class S>
BSTNode<T, S> *BSTNode<T, S>::getLeft() {
	return this->left;
}

/*ostream &operator<<(ostream &lhs, BSTNode<char, string> *rhs) {
	lhs << rhs->getData1() << " = " << rhs->getData2() << endl;
	return lhs;
}*/
