#include "BSTNode.h"
#include <cctype>
#pragma once
using std::fstream;
using std::cout;
class BST {
private:
	BSTNode<char, string> *head;
	//helper function for destroy (public)
	void destroy(BSTNode<char,string> *curr);
	//helper function for insert (public)
	void insert(char chr, string morse, BSTNode<char, string> *curr);
	//helper function for printTree (public)
	void printTree(BSTNode<char, string> *curr) const;
	//helper function for search (public)
	bool search(char chr, BSTNode<char, string> *curr) const;
public:
	//standard constructor
	BST(string fileName = "", string fileName2 = "");

	//standard destructor
	~BST();
	
	//inserts the given character and morse code into the binary tree
	//precondition: chr and morse must be valid codes and cannot be nullptr
	//postcondition: the tree will be changed
	void insert(char chr, string morse);

	//printst the entire tree using In Order Traversal (prints from left to right)
	//precondition: tree must not be empty
	void printTree() const;

	//prints the morse string of the character searched for, if it is found
	//precondition: tree must not be empty and ideally contain the morse code for the character
	//@param chr: must be uppercase, unless there is specifically a node where there is a lowercase character
	bool search(char chr) const;

	//goes through the file and prints out the english text converted into morse code
	//precondition: the constructor must be called and the tree must contain the standard morse code values
	void searchFile(string fileName = "") const;
};

//operator to print out a single node - used for printing the tree
ostream &operator<<(ostream &lhs, BSTNode<char, string> *rhs);