#include "BST.h"
#pragma once
#include <fstream>
using std::ifstream;
class DataAnalysis {
private:
	BST treeSold;
	BST treePurchased;
	ifstream CSVStream;

	//openes the file with the file name
	void openFile(string fileName = "data.csv") { CSVStream.open(fileName); }

	//precondition CSVStream must have a valid line to read (i.e. the end of file must not be reached)
	//splits the line that the stream gets into the 3 variables
	void splitLine(int &units, string &type, string &transaction);

	//reads the entire file and inserts it into the BST
	void readFile();

	//inserts the data into the BST based on the transaction type
	void insertIntoBST(int units, string &type, string &transaction);

	//displays all the necessary trends
	void displayTrends();
public:
	//basic constructor
	DataAnalysis() {
		treeSold = *(new BST());
		treePurchased = *(new BST());
	}
	//only public function
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
	//getting the line
	CSVStream >> line;
	//invalid line
	if (line[0] == '\n' || line[0] == '\0') {
		units = 0;
		type = "", transaction = "";
	}
	//normal line
	else {
		units = atoi(strtok(line, ","));
		type = strtok(NULL, ",");
		transaction = strtok(NULL, "\n");
	}
}

void DataAnalysis::readFile() {
	char temp[500];
	//removing the first line from the stream
	CSVStream.getline(temp, 500);
	while (!CSVStream.eof()) {
		//first splitting the line then adding it to the BST
		string type, transaction;
		int units;
		splitLine(units, type, transaction);
		if (type != "")
			insertIntoBST(units,type,transaction);
	}
	//printing the trees at the end
	cout << "Purchased Tree: " << endl;
	treePurchased.printTree();
	cout << "Sold Tree: " << endl;
	treeSold.printTree();
}

void DataAnalysis::insertIntoBST(int units, string &type, string &transaction) {
	//inserting into the purchased tree
	if (transaction == "Purchased")
		treePurchased.insert(units, type);
	//inserting into the sold tree
	else if (transaction == "Sold")
		treeSold.insert(units, type);
	else
		cout << "Invalid transaction" << endl;
}

void DataAnalysis::displayTrends() {
	//calls the find smallest and find largest of each tree and prints the data to the screen
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