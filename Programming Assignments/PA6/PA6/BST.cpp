#include "BST.h"
//standard constructor
BST::BST(string fileName, string fileName2) {
	this->head = nullptr;
	fstream infile;
	if (fileName == "")
		infile.open("MorseTable.txt", fstream::in);
	else
		infile.open(fileName, fstream::in);
	while (!infile.eof()) {
		char line[50];
		infile.getline(line, 50);
		//getting the initial character
		char *chr = strtok(line, " ");
		//getting the code for the character
		string code = strtok(NULL, "\n");
		//inserting into the tree
		insert(*chr, code);
	}
	printTree(this->head);
	infile.close();
}
//standard destructor
BST::~BST() {
	//destroy(this->head);
}
void BST::insert(char chr, string morse) {
	insert(chr, morse, this->head);
}
void BST::printTree() const{
	printTree(this->head);
}
void BST::searchFile(string fileName) const{
	fstream infile;
	if (fileName != "")
		infile.open(fileName, fstream::in);
	else
		infile.open("Convert.txt", fstream::in);
	while (!infile.eof()) {
		char line[100];
		infile.getline(line, 100);
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == '\n')
				cout << endl;
			else if (line[i] == ' ')
				cout << " ";
			else
				search(std::toupper(line[i]));
		}
		cout << endl;
	}
	infile.close();
}
//prints the morse string of the character searched for, if it is found
bool BST::search(char chr) const{
	return search(chr, this->head);
}
void BST::destroy(BSTNode<char, string> *curr) {

}
void BST::insert(char chr, string morse, BSTNode<char, string> *curr) {
	//empty tree
	if (curr == nullptr)
		head = new BSTNode<char, string>(chr, morse);
	else {
		if (curr->getData1() > chr) {
			//inserting data into the left node
			if (curr->getLeft() == nullptr)
				curr->setLeft(new BSTNode<char, string>(chr, morse));
			//continuing down the tree
			else
				insert(chr, morse, curr->getLeft());
		}
		else if (curr->getData1() < chr) {
			//inserting data into the right node
			if (curr->getRight() == nullptr)
				curr->setRight(new BSTNode<char, string>(chr, morse));
			//continuing down the trees
			else
				insert(chr, morse, curr->getRight());
		}
		//duplicate data, stop the insert
		else
			std::cout << "Duplicate data found!\n";
	}
}
void BST::printTree(BSTNode<char, string> *curr) const{
	//using the inOrderTraversal algorithm
	if (curr != nullptr) {
		printTree(curr->getLeft());
		std::cout << curr;
		printTree(curr->getRight());
	}
}
void BST::convertToMorse(fstream &infile) {
	//printing out each line in the file
	while (!infile.eof()) {
		char str[100];
		//getting each line
		infile.getline(str, 100);
		//printing out each character in the line
		for (int i = 0; *(str + i) != '\0'; i++) {
			//special case for new line
			if (*(str + i) == '\n')
				cout << endl;
			//regular case, print out the morse conversion of the character
			else
				search(*(str + i));
		}
	}
}
bool BST::search(char chr, BSTNode<char, string> *curr) const{
	//using inOrderTraveral algorithm
	//couldn't find the data
	if (curr == nullptr || curr->getData1() == chr) {
		cout << curr->getData2()<<"   ";
		return true;
	}
	if (curr->getData1() < chr)
		return search(chr, curr->getRight());
	return search(chr, curr->getLeft());
}
ostream &operator<<(ostream &lhs, BSTNode<char, string> *rhs) {
	lhs << rhs->getData1() << " = " << rhs->getData2() << endl;
	return lhs;
}