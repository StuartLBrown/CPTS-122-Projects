#include <iostream>
template <class T>
class Node {
public:
	Node(T *newData = nullptr);
	Node(Node<T> &copy);
	Node<T> *getRight();
	Node<T> *getLeft();
	T getData();
	void setRight(Node<T> *node);
	void setLeft(Node<T> *node);
	void setData(T &newData);
private:
	T *data;
	Node<T> *right, *left;
};

template <class T>
Node<T>::Node(Node<T> &copy) {
	this->data = new T;
	*(this->data) = *(copy.data);
	this->left = copy->left;
	this->right = copy->right;
}

template <class T>
Node<T>::Node(T *newData) {
	data = newData;
	right = left = nullptr;
}
template <class T>
Node<T> *Node<T>::getRight() {
	return right;
}

template <class T>
Node<T> *Node<T>::getLeft() {
	return left;
}
template <class T>
int Node<T>::getData() {
	return *data;
}
template <class T>
void Node<T>::setRight(Node<T> *node) {
	this->right = node;
}
template <class T>
void Node<T>::setLeft(Node<T> *node) {
	this->left = node;
}
template <class T>
void Node<T>::setData(T &newData) {
	*(this->data) = newData;
}