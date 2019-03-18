#include "BST.h"
//standard constructor
BST::BST(string fileName, string fileName2) {
	this->head = nullptr;
	fstream infile;
	//opening the file for the morsetable to be put into the tree
	if (fileName == "")
		infile.open("MorseTable.txt", fstream::in);
	else
		infile.open(fileName, fstream::in);
	//putting the file into the tree file must be in format (character) (morse code)
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
	//printing the completed morse tree
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
	//opening the file
	if (fileName != "")
		infile.open(fileName, fstream::in);
	else
		infile.open("Convert.txt", fstream::in);
	//searching through the entire file
	while (!infile.eof()) {
		char line[100];
		infile.getline(line, 100);
		//going through each character in the line and printing the morse code equivalent
		for (int i = 0; line[i] != '\0'; i++) {
			//special case for new line
			if (line[i] == '\n')
				cout << endl;
			//special case for space
			else if (line[i] == ' ')
				cout << " ";
			//regular case
			else
				search(std::toupper(line[i]));//note have to convert to an uppercase character beforehand
		}
		cout << endl;
	}
	//closing the file
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
bool BST::search(char chr, BSTNode<char, string> *curr) const{
	//using inOrderTraveral algorithm
	//reached the bottom of the tree
	if (curr == nullptr || curr->getData1() == chr) {
		cout << curr->getData2()<<"   ";
		return true;
	}
	//traversing down the right
	if (curr->getData1() < chr)
		return search(chr, curr->getRight());
	//traversing down the left
	return search(chr, curr->getLeft());
}
ostream &operator<<(ostream &lhs, BSTNode<char, string> *rhs) {
	//printing out the node
	lhs << rhs->getData1() << " = " << rhs->getData2() << endl;
	return lhs;
}