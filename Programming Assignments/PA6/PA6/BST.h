#include "BSTNode.h"
#include <cctype>
#pragma once
using std::fstream;
using std::cout;
class BST {
private:
	BSTNode<char, string> *head;
	void destroy(BSTNode<char,string> *curr);
	void insert(char chr, string morse, BSTNode<char, string> *curr);
	void printTree(BSTNode<char, string> *curr);
	bool search(char chr, BSTNode<char, string> *curr);
public:
	//standard constructor
	BST(string fileName = "", string fileName2 = "");
	//standard destructor
	~BST();
	void insert(char chr, string morse);
	//precondition infile must already be opened
	void convertToMorse(fstream &infile);
	void printTree();
	//prints the morse string of the character searched for, if it is found
	bool search(char chr);
};