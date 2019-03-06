#include "Node.h"
using std::cout;
using std::endl;
class BST {
public:
	BST();

	//public version 
	bool insert(int newData);

	void inOrderTraversal();
private:

	Node *root;

	//private version (used for recursion)
	bool insert(Node *tree, int newData);

	void inOrderTraversal(Node *tree);
};