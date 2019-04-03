#include "Node.h"
#include <iostream>
template <class T>
class List {
private:
	Node<T> *head;
public:
	//default + copy constructor
	List<T>() { head = nullptr; }

	List<T>(const List<T> &copy) { head = copy->getHead(); }

	//standrd getter and setter
	Node<T> *getHead() const { return head; }
	void setHead(Node<T> *_head) { head = _head; }
	
	//inserts a node at the front of the list
	void insertAtFront(T data);

	//returns true if the list is empty, false if not
	bool isEmpty() { return head == nullptr; }
};
template <class T>
void List<T>::insertAtFront(T data) {
	Node<T> *temp = new Node<T>(data);
	if (isEmpty()) {
		head = temp;
		head->setNext(nullptr);
	}
	else {
		temp->setNext(head);
		head = temp;
	}
}