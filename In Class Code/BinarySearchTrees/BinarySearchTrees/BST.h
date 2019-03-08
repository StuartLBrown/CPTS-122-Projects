#include "Node.h"
#include <string>
using std::cout;
using std::endl;
//class template / generic
template<class T>
class BST {
public:
	BST();

	//public version 
	bool insert(T newData);
	void inOrderTraversal();
private:

	Node<T> *root;

	//private version (used for recursion)
	bool insert(Node<T> *tree, T newData);

	void inOrderTraversal(Node<T> *tree);
};
template<class T>
BST<T>::BST() {
	root = nullptr;
}
template<class T>
bool BST<T>::insert(T newData) {
	return insert(this->root, newData);
}
template<class T>
bool BST<T>::insert(Node<T> *tree, T newData) {
	//empty tree
	if (tree == nullptr) {
		T *temp = new T;
		*temp = newData;
		root = new Node<T>(temp);
		return true;
	}
	else {//recursive step
		  //trying to find the correct spot in the tree
		if (tree->getData() > newData) {
			if (tree->getLeft() == nullptr) {
				T *temp = new T;
				*temp = newData;
				tree->setLeft(new Node<T>(temp));
				return true;
			}
			else
				return insert(tree->getLeft(), newData);
		}
		else if (tree->getData()<newData) {
			if (tree->getRight() == nullptr) {
				T *temp = new T;
				*temp = newData;
				tree->setRight(new Node<T>(temp));
				return true;
			}
			else
				return insert(tree->getRight(), newData);
		}
		else {
			std::cout << "Duplicate data: " << newData << std::endl;
		}
	}
	return false;
}
template<class T>
void BST<T>::inOrderTraversal() {
	inOrderTraversal(this->root);
}
template<class T>
void BST<T>::inOrderTraversal(Node<T> *tree) {
	if (tree != nullptr) {
		inOrderTraversal(tree->getLeft());
		cout << tree->getData() << endl;
		inOrderTraversal(tree->getRight());
	}
}
