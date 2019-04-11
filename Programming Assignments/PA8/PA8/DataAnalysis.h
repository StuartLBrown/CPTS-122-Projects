#include "BST.h"
#pragma once
#include <fstream>
using std::ifstream;
class DataAnalysis {
private:
	BST treeSold;
	BST treePurchased;
	ifstream CSVStream;

	void openFile(string fileName = "data.csv") { CSVStream.open(fileName); }

	//precondition CSVStream must have a valid line to read (i.e. the end of file must not be reached)
	void splitLine(int &units, string &type, string &transaction);

	void readFile();
	void insertIntoBST(int units, string &type, string &transaction);
	void displayTrends();
public:
	DataAnalysis() {
		treeSold = *(new BST());
		treePurchased = *(new BST());
	}
	void runAnalysis();
};
void DataAnalysis::runAnalysis() {
	openFile();
	readFile();
	system("pause");
	system("cls");
	displayTrends();
}

void DataAnalysis::splitLine(int &units, string &type, string &transaction) {
	char line[300];
	CSVStream >> line;
	if (line[0] == '\n' || line[0] == '\0') {
		units = 0;
		type = "", transaction = "";
	}
	else {
		units = atoi(strtok(line, ","));
		type = strtok(NULL, ",");
		transaction = strtok(NULL, "\n");
	}
}

void DataAnalysis::readFile() {
	char temp[500];
	CSVStream.getline(temp, 500);
	while (!CSVStream.eof()) {
		string type, transaction;
		int units;
		splitLine(units, type, transaction);
		if (type != "")
			insertIntoBST(units,type,transaction);
	}
	cout << "Purchased Tree: " << endl;
	treePurchased.printTree();
	cout << "Sold Tree: " << endl;
	treeSold.printTree();
}

void DataAnalysis::insertIntoBST(int units, string &type, string &transaction) {
	if (transaction == "Purchased")
		treePurchased.insert(units, type);
	else if (transaction == "Sold")
		treeSold.insert(units, type);
	else
		cout << "Invalid transaction" << endl;
}

void DataAnalysis::displayTrends() {
	cout << "Smallest Purchased Units: ";
	treePurchased.findSmallest().printData();
	cout << "Largest Purchased Units: ";
	treePurchased.findLargest().printData();

	system("pause");

	cout << "Smallest Sold Units: ";
	treeSold.findSmallest().printData();
	cout << "Largest Sold Units: ";
	treeSold.findLargest().printData();
}