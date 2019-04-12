#include <iostream>
#pragma once
using std::cout;
template<class T> class List;
template<class T>
class Node
{
	friend class List<T>;
public:
	Node(const T &newData) {
		data = newData;
		nextPtr = nullptr;
	}// copy constructor
	T getData() const { return data; }// return data in the node
private:
	T data;                 // data
	Node<T> *nextPtr; // next node in the list
};

template <class T>
class List {
public:
	List<T>() {
		lastPtr = firstPtr = nullptr;
	}// constructor

	~List<T>() {
		if (!isEmpty()) {
			Node<T> *temp = firstPtr;
			while (temp != nullptr) {
				temp = temp->nextPtr;
				delete firstPtr;
				firstPtr = temp;
			}
		}
	}// destructor

	void insertAtFront(const T &newData);

	void insertAtBack(const T &newData);

	bool removeFromFront(T &removedData);

	bool removeFromBack(T &removedData);

	bool isEmpty() const { return firstPtr==nullptr&&lastPtr==nullptr; }

	void print() const {
		Node<T> *curr = firstPtr;
		while (curr != nullptr) {
			cout << curr->getData()<<std::endl;
			curr = curr->nextPtr;
		}
	}

private:
	Node<T> *firstPtr;  // pointer to first node
	Node<T> *lastPtr;   // pointer to last node
						// Utility function to allocate a new node
	Node<T> *getNewNode(const T &newData) { return new Node<T>(newData); }
};

template<class T>
void List<T>::insertAtFront(const T &newData) {
	if (isEmpty())
		firstPtr = lastPtr = getNewNode(newData);
	else {
		Node<T> *temp = getNewNode(newData);
		temp->nextPtr = firstPtr;
		firstPtr = temp;
	}
}

template<class T>
void List<T>::insertAtBack(const T &newData) {
	if (isEmpty())
		firstPtr = lastPtr = getNewNode(newData);
	else {
		lastPtr->nextPtr = getNewNode(newData);
		lastPtr = lastPtr->nextPtr;
	}
}

template<class T>
bool List<T>::removeFromFront(T &removedData) {
	if (isEmpty()) {
		return false;
	}
	else {
		if (firstPtr == lastPtr) {
			removedData = firstPtr->getData();
			delete firstPtr;
			firstPtr = lastPtr = nullptr;
		}
		else {
			Node<T> *temp = firstPtr;
			firstPtr = firstPtr->nextPtr;
			removedData = temp->data;
			delete temp;
		}
	}
}

template<class T>
bool List<T>::removeFromBack(T &removedData) {
	if (isEmpty()) {
		return false;
	}
	else if (firstPtr == lastPtr) {
		removedData = lastPtr->data;
		delete firstPtr;
		return true;
		firstPtr = lastPtr = nullptr;
	}
	Node<T> *curr = firstPtr;
	while (curr->nextPtr->nextPtr != nullptr) {
		curr = curr->nextPtr;
	}
	removedData = curr->data;
	curr->nextPtr = nullptr;
	delete lastPtr;
	lastPtr = curr;
	return true;
}