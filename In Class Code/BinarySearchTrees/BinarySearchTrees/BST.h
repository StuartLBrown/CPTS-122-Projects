#include "Node.h"
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