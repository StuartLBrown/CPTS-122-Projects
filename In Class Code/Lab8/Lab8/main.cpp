#include "BST.h"
int main(void) {
	/*BST tree;
	string temp2 = "42";
	tree.insertNode(temp2);
	temp2 = "25";
	tree.insertNode(temp2);
	temp2 = "10";
	tree.insertNode(temp2);
	temp2 = "30";
	tree.insertNode(temp2);
	temp2 = "15";
	tree.insertNode(temp2);
	temp2 = "75";
	tree.insertNode(temp2);
	temp2 = "65";
	tree.insertNode(temp2);
	temp2 = "70";
	tree.insertNode(temp2);
	tree.postOrderTraversal();
	std::cout << "\n\n";
	tree.preOrderTraversal();*/
	ifstream inFile("names.txt");
	BST temp;
	string *names = readNames(inFile);
	for (int i = 0; i<5; i++) {
		std::cout << *(names + i) << std::endl;
	}
	for (int i = 0; *(names+i)!=""; i++) {
		temp.insertNode(*(names + i));
	}
	temp.inOrderTraversal(names);
	for (int i = 0; *(names+i)!=""; i++) {
		std::cout << *(names + i) << std::endl;
	}
	return 0;
}