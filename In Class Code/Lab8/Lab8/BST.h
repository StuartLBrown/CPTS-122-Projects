#include "Node.h"
#include <array>
#include <fstream>
#pragma once
using std::ifstream;
class BST {
private:
	Node<string> *head;
	bool insertNode(string &data, Node<string> *tree) {
		if (tree == nullptr) {
			string *temp = new string(data);
			this->head = new Node<string>(temp);
			return true;
		}
		else {
			if (tree->getData() > data) {
				if (tree->getLeft() == nullptr) {
					string *temp = new string(data);
					tree->setLeft(new Node<string>(temp));
					return true;
				}
				else
					return insertNode(data, tree->getLeft());
			}
			else if (tree->getData() < data) {
				if (tree->getRight() == nullptr) {
					string *temp = new string(data);
					tree->setRight(new Node<string>(temp));
					return true;
				}
				else
					return insertNode(data, tree->getRight());
			}
			else
				std::cout << "Duplicate data: " << data << std::endl;
		}
		return false;
	}
	void inOrderTraversal(Node<string> *tree) {
		if (tree != nullptr) {
			inOrderTraversal(tree->getLeft());
			std::cout << tree->getData() << std::endl;
			inOrderTraversal(tree->getRight());
		}
	}
	void inOrderTraversal(string *data, Node<string> *tree) {
		if (tree != nullptr) {
			inOrderTraversal(data, tree->getLeft());
			data->append(tree->getData());
			inOrderTraversal(data, tree->getRight());
		}
	}
	void preOrderTraversal(Node<string> *tree) {
		if (tree != nullptr) {
			std::cout << tree->getData() << std::endl;
			preOrderTraversal(tree->getLeft());
			preOrderTraversal(tree->getRight());
		}
	}
	void postOrderTraversal(Node<string> *tree) {
		if (tree != nullptr) {
			postOrderTraversal(tree->getLeft());
			postOrderTraversal(tree->getRight());
			std::cout << tree->getData() << std::endl;
		}
	}
	void destroyTree(Node<string> *tree) {
		if (tree != nullptr) {
			destroyTree(tree->getLeft());
			destroyTree(tree->getRight());
			delete tree;
		}
	}
public:
	BST() {
		this->head = nullptr;
	}
	~BST(void) {
		destroyTree(this->head);
	}
	Node<string> *getHead(void) {
		return this->head;
	}
	void setHead(Node<string> *_head) {
		this->head = head;
	}
	bool insertNode(string &data) {
		return insertNode(data, this->head);
	}
	void inOrderTraversal(void) {
		inOrderTraversal(this->head);
	}
	void inOrderTraversal(string *data) {
		inOrderTraversal(data, this->head);
	}
	void preOrderTraversal(void) {
		preOrderTraversal(this->head);
	}
	void postOrderTraversal(void) {
		postOrderTraversal(this->head);
	}
	bool isEmpty(void) {
		return nullptr == this->head;
	}
};
ostream &operator<<(ostream &lhs, BST &rhs) {
	rhs.inOrderTraversal();
	return lhs;
}
string *readNames(ifstream &file) {
	string names[5];
	int i = 0;
	for (; !file.eof(); i++) {
		char *temp = (char*)malloc(sizeof(char) * 100);
		file.getline(temp, 100);
		if (*temp == '\n')
			break;
		names[i]= temp;
	}
	return names;
}