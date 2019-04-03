#pragma once
template <class T>
class Node {
public:
	//standard constructor
	Node<T>(T _data);

	//getters and setters
	Node<T> *getNext();
	T getData();
	void setData(T newData);
	void setNext(Node<T> *newNext);
private:
	//member variables
	Node<T> *next;
	T data;
};
template <class T>
Node<T>::Node<T>(T _data) {
	data = _data;
	next = nullptr;
}
template <class T>
Node<T> *Node<T>::getNext() {
	return this->next;
}
template <class T>
T Node<T>::getData() {
	return this->data;
}
template <class T>
void Node<T>::setData(T newData) {
	this->data = newData;
}
template <class T>
void Node<T>::setNext(Node<T> *newNext) {
	this->next = newNext;
}