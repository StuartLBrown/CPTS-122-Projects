#include "BST.h"
int main(void) {
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(15);
	tree.insert(20);
	tree.insert(2);
	tree.insert(20);
	tree.insert(17);
	tree.inOrderTraversal();
	return 0;
}