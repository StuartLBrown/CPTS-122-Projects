#include "TransactionNode.h"
#pragma once
class BST {
private:
	Node *root;
	void destroyTree(TransactionNode *tree);
	void insert(TransactionNode *tree, int units, string &name);
	void printTree(TransactionNode *tree);
public:
	BST() { root = nullptr; }
	~BST() { destroyTree(dynamic_cast<TransactionNode*>(root)); }
	Node *getRoot() { return root; }
	void setRoot(Node *newRoot) { root = newRoot; }
	void insert(int units, string &name);
	void printTree() { printTree(dynamic_cast<TransactionNode*>(root)); }
	TransactionNode &findSmallest();
	TransactionNode &findLargest();
};

TransactionNode &BST::findSmallest() {
	TransactionNode *temp = dynamic_cast<TransactionNode*>(root);
	while (temp->getLeft() != nullptr) {
		temp->setLeft(temp->getLeft());
	}
	return *temp;
}
TransactionNode &BST::findLargest() {
	TransactionNode *temp = dynamic_cast<TransactionNode*>(root);
	while (temp->getRight() != nullptr) {
		temp->setRight(temp->getRight());
	}
	return *temp;
}

void BST::insert(TransactionNode *tree, int units, string &name) {
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
	insert(dynamic_cast<TransactionNode*>(root), units, name);
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
		destroyTree(dynamic_cast<TransactionNode*>(tree->getLeft()));
		destroyTree(dynamic_cast<TransactionNode*>(tree->getRight()));
		delete tree;
	}
}