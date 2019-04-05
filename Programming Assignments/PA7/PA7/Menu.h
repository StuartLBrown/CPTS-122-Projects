#include "List.h"
#include "Data.h"
#include <fstream>
#include <time.h>
using std::fstream;
using std::cout;
using std::cin;
using std::endl;
using std::to_string;
#pragma once
class Menu {
private:
	List<Data> list;
	fstream courses, master;
public:
	Menu();

	void displayMenu();


	void markAbsences();


	void readCourseList();


	void readMasterList();


	void storeMasterList();


	void generateReport(int minAbsences);
};
Menu::Menu() {
	list = *(new List<Data>());
}

void Menu::displayMenu() {
	int input = 1;
	while (input >= 1 && input <= 5) {
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
			while (input2 <= 0 || input2 >= 3) {
				cout << "Enter an option:\n1.Generate a report for all students\n2.Generate a report with students that have at least n absences\n";
				cin >> input2;
			}
			if (input2 == 1)
				generateReport(-1);
			else {
				while (input2 >= -1) {
					cout << "Enter a minimum number of absences to generate a report from: ";
					cin >> input2;
				}
				generateReport(input2);
			}
		}
		system("cls");
	}
}

void Menu::markAbsences() {
	system("cls");
	Node<Data> *curr(list.getHead());
	while (curr != nullptr) {
		Data d = curr->getData();
		time_t t = time(0);
		struct tm *now = localtime(&t);
		string date = to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + "/" + to_string(now->tm_year + 1900);
		int input = -1;
		while (input <= -1 || input >= 2) {
			cout << "Was " << d.name << " absent today " << date << "?\n1 for yes, 0 for no: ";
			cin >> input;
			if (input == 1 || input == 2)
				break;
		}
		if (input == 1) {
			d.addAbscence(date);
			d.setNAbsences(d.getNAbsences() + 1);
		}
		curr->setData(d);
		curr = curr->getNext();

		system("cls");
	}
	system("cls");
}
void Menu::readCourseList() {
	courses.open("classList.csv");
	char line[300];
	courses.getline(line, 300);
	while (!courses.eof()) {
		courses.getline(line, 300);
		if (line[0] == '\n')
			break;
		int n = atoi(strtok(line, ",")), ID = atoi(strtok(NULL, ","));
		string s1 = strtok(NULL, ",");
		s1.append(",");
		s1.append(strtok(NULL, ","));
		string s2 = strtok(NULL, ",");
		string s3 = strtok(NULL, ",");
		string s4 = strtok(NULL, ",");
		string s5 = strtok(NULL, "\n");
		Data temp(n,ID, s1, s2, s3, s4, s5,0);
		list.insertAtFront(temp);
	}
	courses.close();
}

void Menu::storeMasterList() {
	master.close();
	master.open("masterList.csv", fstream::out);
	Node<Data> *curr = list.getHead();
	master << ",ID,Name,Email,Units,Program,Level,Num Absences,Date Absence\n";
	for (int i = 0; curr != nullptr; i++) {
		Data temp = curr->getData();
		master << i + 1 << "," << temp.getID() << "," << temp.name << "," << temp.email << "," << temp.units << "," << temp.major << "," << temp.level << "," << temp.getNAbsences();
		Stack s(temp.getStack());
		while (!s.isEmpty()) {
			master << "," << s.pop();
		}
		master << endl;
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
		int n = atoi(strtok(line, ",")), ID = atoi(strtok(NULL, ","));
		string s1 = strtok(NULL, ",");
		s1.append(",");
		s1.append(strtok(NULL, ","));
		string s2 = strtok(NULL, ",");
		string s3 = strtok(NULL, ",");
		string s4 = strtok(NULL, ",");
		string s5 = strtok(NULL, ",");
		int nAbsences = atoi(strtok(NULL, ","));
		Data temp(n, ID, s1, s2, s3, s4, s5, nAbsences);
		for (int i = 0; i < temp.getNAbsences()-1; i++) {
			string date = strtok(NULL, ",");
			temp.addAbscence(date);
		}
		string date = strtok(NULL, "\n");
		temp.addAbscence(date);
	}
}

void Menu::generateReport(int minAbsences) {
	Node<Data> *curr = list.getHead();
	while (curr != nullptr) {
		if (minAbsences == -1) {
			if (curr->getData().getNAbsences() == 0)
				cout << curr->getData().name << " was never absent" << endl;
			else
				cout << curr->getData().name << " was most recently absent on " << curr->getData().peekStack() << " and has " << curr->getData().getNAbsences() << " absences" << endl;
		}
		else {
			if (curr->getData().getNAbsences() >= minAbsences) {
				cout << curr->getData().name << " has " << curr->getData().getNAbsences() << " absences" << endl;
			}
		}
		curr = curr->getNext();
	}
	system("pause");
	system("cls");
}