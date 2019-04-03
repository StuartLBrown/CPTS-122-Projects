#include "List.h"
#include "Data.h"
#include <fstream>
#include <time.h>
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
#pragma once
class Menu {
private:
	List<Data> list;
	fstream courses, master;
public:
	Menu(string fileName1 = "classList.csv", string fileName2 = "masterList.csv");

	void displayMenu();

	void markAbsences();

	void readCourseList();


	void readMasterList();


	void storeMasterList();


	void generateReport(int minAbsences);
};
Menu::Menu(string f1, string f2) {
	list = *(new List<Data>());
	courses.open(f1, fstream::in);
	courses.open(f2, fstream::in);
}

void Menu::displayMenu() {
	int input = 0;
	while (input != 0 && input != 6) {
		cout << "1. Import course list\n2. Load master list\n3. Store master list\n4. Mark Absences\n5. Generate report\n6. Exit\n";
		cin >> input;
		if (input == 1)
			readCourseList();
		else if (input == 2)
			readMasterList();
		else if (input == 3)
			storeMasterList();
		else if (input == 4)
			markAbsences();
		else if (input == 5) {
			int input2 = -1;
			while (input2 >= -1) {
				cout << "Enter a minimum number of absences to generate a report from: ";
				cin >> input2;
			}
			generateReport(input2);
		}
		system("cls");
	}
}

void Menu::markAbsences() {
	Node<Data> *curr = list.getHead();
	while (curr != nullptr) {
		time_t t = time(0);
		struct tm *now = localtime(&t);
		string date = (now->tm_year + 1900) + "/" + (now->tm_mon + 1) + '/' + now->tm_mday;
		cout << "Was " << curr->getData().name << " absent today " << date << " 1 for yes, 0 for no"<<endl;
		int input = -1;
		while (input <= -1 || input >= 2) {
			cout << "Was " << curr->getData().name << " absent today " << date << " 1 for yes, 0 for no" << endl;
			cin >> input;
		}
		if (input == 1)
			curr->getData().addAbscence(date);
	}
}
void Menu::readCourseList() {
	char line[300];
	courses.getline(line, 300);
	while (!courses.eof()) {
		courses.getline(line, 300);
		if (line[0] == '\n')
			break;
		Data temp(atoi(strtok(line, ",")), atoi(strtok(NULL, ",")), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, "\n"),0);
		list.insertAtFront(temp);
	}
}

void Menu::storeMasterList() {
	master.close();
	master.open("masterList.csv", fstream::out);
	Node<Data> *curr = list.getHead();
	master << ",ID,Name,Email,Units,Program,Level,Num Absences,Date Absence\n";
	for (int i = 0; curr != nullptr; i++) {
		Data temp = curr->getData();
		master << i + 1 << "," << temp.getID() << "," << temp.name << "," << temp.email << "," << temp.units << "," << temp.major << "," << temp.level << "," << temp.getNAbsences() << "," << temp.removeAbsence() << endl;
		curr = curr->getNext();
	}
}

void Menu::readMasterList() {
	master.close();
	master.open("masterlist.csv", fstream::in);
	char line[300];
	master.getline(line, 300);
	while (!master.eof()) {
		master.getline(line, 300);
		if (line[0] == '\n')
			break;
		Data temp(atoi(strtok(line, ",")), atoi(strtok(NULL, ",")), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), strtok(NULL, ","), atoi(strtok(NULL, ","))-1);
		string date = strtok(NULL, "\n");
		temp.addAbscence(date);
	}
}