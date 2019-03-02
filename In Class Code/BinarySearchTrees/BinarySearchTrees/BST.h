#include "Node.h"
class BST {
public:
	BST();

	//public version 
	bool insert(int newData);
private:

	Node *root;

	//private version (used for recursion)
	bool insert(Node *tree, int newData);
};