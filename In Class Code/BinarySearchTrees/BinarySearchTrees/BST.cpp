#include "BST.h"
BST::BST() {
	root = nullptr;
}

bool BST::insert(int newData) {
	return insert(this->root, newData);
}

bool BST::insert(Node *tree, int newData) {	
	//empty tree
	if (tree == nullptr) {
		int *temp = new int(newData);
		root = new Node(temp);
		return true;
	}
	else {//recursive step
		//trying to find the correct spot in the tree
		if (tree->getData() > newData) {
			if (tree->getLeft() == nullptr) {
				int *temp = new int(newData);
				tree->setLeft(new Node(temp));
				return true;
			}
			else
				return insert(tree->getLeft(), newData);
		}
		else if(tree->getData()<newData){
			if (tree->getRight() == nullptr) {
				int *temp = new int(newData);
				tree->setRight(new Node(temp));
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

void BST::inOrderTraversal() {
	inOrderTraversal(this->root);
}

void BST::inOrderTraversal(Node *tree) {
	if (tree != nullptr) {
		inOrderTraversal(tree->getLeft());
		cout << tree->getData() << endl;
		inOrderTraversal(tree->getRight());
	}
}
