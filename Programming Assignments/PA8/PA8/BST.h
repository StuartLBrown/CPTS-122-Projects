#include "TransactionNode.h"
#pragma once
class BST {
private:
	Node *root;
	//postorder traversal
	void destroyTree(TransactionNode *tree);

	//inserts a node recursively into the list
	void insert(TransactionNode *&tree, int units, string &name);

	//prints the entire tree recursively using inOrderTraversal
	void printTree(TransactionNode *tree);

	//recursive function to go down the left most branch
	TransactionNode &findSmallest(TransactionNode *tree);

	//same as largest, except for right side
	TransactionNode &findLargest(TransactionNode *tree);
public:
	//default constructor
	BST() { root = nullptr; }

	//destructor, just calls destroy tree
	~BST() { destroyTree((TransactionNode*&)(root)); }

	//getter and setter
	Node *getRoot() { return root; }
	void setRoot(Node *newRoot) { root = newRoot; }

	//inserts a node into the list
	void insert(int units, string &name);

	//prints the tree by using inOrder traversal
	void printTree() { printTree(dynamic_cast<TransactionNode*>(root)); }

	//goes down the left side of the list until the end is reached and returns that node
	TransactionNode &findSmallest();

	//goes down the right side of the list until the end is reached and returns that node
	TransactionNode &findLargest();
};

TransactionNode &BST::findSmallest() {
	return findSmallest((TransactionNode*)root);
}
TransactionNode &BST::findLargest() {
	return findLargest((TransactionNode*)root);
}

void BST::insert(TransactionNode *&tree, int units, string &name) {
	//empty tree
	if (tree == nullptr)
		tree = new TransactionNode(name, units);
	else if (tree->getUnits() > units) {
		//insert node into the empty node
		if (tree->getLeft() == nullptr)
			tree->setLeft(new TransactionNode(name, units));
		else {
			//go down the left side of the tree recursively
			TransactionNode *temp = dynamic_cast<TransactionNode*>(tree->getLeft());
			insert(temp, units, name);
		}
	}
	else if (tree->getUnits() <= units) {
		//insert node into the empty node
		if (tree->getRight() == nullptr)
			tree->setRight(new TransactionNode(name, units));
		else {
			//goes down the right side of the tree recursively
			TransactionNode *temp = dynamic_cast<TransactionNode*>(tree->getRight());
			insert(temp, units, name);
		}
	}
	else
		cout << "Error inserting into BST" << endl;
}

void BST::insert(int units, string &name) {
	insert((TransactionNode*&)(root), units, name);
}

void BST::printTree(TransactionNode *tree) {
	//inOrder Traversal
	if (tree != nullptr) {
		printTree(dynamic_cast<TransactionNode*>(tree->getLeft()));
		tree->printData();
		printTree(dynamic_cast<TransactionNode*>(tree->getRight()));
	}
}

void BST::destroyTree(TransactionNode *tree) {
	//postOrder traversal
	if (tree != nullptr) {
		destroyTree((TransactionNode*)(tree->getLeft()));
		destroyTree((TransactionNode*)(tree->getRight()));
		delete tree;
	}
}

TransactionNode &BST::findSmallest(TransactionNode *tree) {
	//going down the left side of the tree
	if (tree->getLeft() == nullptr)
		return *tree;
	findSmallest((TransactionNode*)tree->getLeft());
}
TransactionNode &BST::findLargest(TransactionNode *tree) {
	//going down the right side of the tree
	if (tree->getRight() == nullptr)
		return *tree;
	findLargest((TransactionNode*)tree->getRight());
}