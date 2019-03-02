#include "BST.h"
BST::BST() {
	root = nullptr;
}

bool BST::insert(int newData) {
	return insert(this->root, newData);
}

bool BST::insert(Node *tree, int newData) {
	int *temp = new int(newData);
	//empty tree
	if (tree == nullptr) {
		root = new Node(temp);
		return true;
	}
	else {//recursive step
		//trying to find the correct spot in the tree
		if (tree->getData() > newData) {
			if (tree->getLeft() == nullptr)
				tree->setLeft(new Node(temp));
			else
				return insert(tree->getLeft(), newData);
		}
		else {
			if (tree->getRight() == nullptr)
				tree->setRight(new Node(temp));
			else
				return insert(tree->getRight(), newData);
		}
	}
	return false;
}
