#include "TransactionNode.h"
#pragma once
class BST {
private:
	Node *root;
	void destroyTree(TransactionNode *tree);
	void insert(TransactionNode *&tree, int units, string &name);
	void printTree(TransactionNode *tree);
	TransactionNode &findSmallest(TransactionNode *tree);
	TransactionNode &findLargest(TransactionNode *tree);
public:
	BST() { root = nullptr; }
	~BST() { destroyTree((TransactionNode*&)(root)); }
	Node *getRoot() { return root; }
	void setRoot(Node *newRoot) { root = newRoot; }
	void insert(int units, string &name);
	void printTree() { printTree(dynamic_cast<TransactionNode*>(root)); }
	TransactionNode &findSmallest();
	TransactionNode &findLargest();
};

TransactionNode &BST::findSmallest() {
	return findSmallest((TransactionNode*)root);
}
TransactionNode &BST::findLargest() {
	return findLargest((TransactionNode*)root);
}

void BST::insert(TransactionNode *&tree, int units, string &name) {
	if (tree == nullptr)
		tree = new TransactionNode(name, units);
	else if (tree->getUnits() > units) {
		if (tree->getLeft() == nullptr)
			tree->setLeft(new TransactionNode(name, units));
		else {
			TransactionNode *temp = dynamic_cast<TransactionNode*>(tree->getLeft());
			insert(temp, units, name);
		}
	}
	else if (tree->getUnits() <= units) {
		if (tree->getRight() == nullptr)
			tree->setRight(new TransactionNode(name, units));
		else {
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
	if (tree != nullptr) {
		printTree(dynamic_cast<TransactionNode*>(tree->getLeft()));
		tree->printData();
		printTree(dynamic_cast<TransactionNode*>(tree->getRight()));
	}
}

void BST::destroyTree(TransactionNode *tree) {
	if (tree != nullptr) {
		destroyTree((TransactionNode*)(tree->getLeft()));
		destroyTree((TransactionNode*)(tree->getRight()));
		delete tree;
	}
}

TransactionNode &BST::findSmallest(TransactionNode *tree) {
	if (tree->getLeft() == nullptr)
		return *tree;
	findSmallest((TransactionNode*)tree->getLeft());
}
TransactionNode &BST::findLargest(TransactionNode *tree) {
	if (tree->getRight() == nullptr)
		return *tree;
	findLargest((TransactionNode*)tree->getRight());
}