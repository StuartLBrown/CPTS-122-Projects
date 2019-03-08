#include "BST.h"
using std::string;
int main(void) {
	Node<int> n1;
	Node<string> n2;
	BST<string> tree;
	string s1 = "cat";
	tree.insert(s1);
	s1 = "dog";
	tree.insert(s1);
	s1 = "cougar";
	tree.insert(s1);
	tree.inOrderTraversal();
	/*
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(20);
	tree.insert(2);
	tree.insert(20);
	tree.insert(17);
	tree.inOrderTraversal();*/
	return 0;
}