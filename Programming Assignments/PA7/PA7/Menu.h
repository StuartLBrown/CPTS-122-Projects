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
	//default constructor
	Menu();

	//displays the main menu for the application
	void displayMenu();

	//allows for the user to mark all students in the list absent or not for today
	void markAbsences();

	//reads the course list form the classList.csv file and overwrites the values in the list
	void readCourseList();

	//reads the master list from masterList.csv and overwrites the values in the list
	void readMasterList();

	//stores the contents of the list, including all the absences for each student in the stack into masterList.csv
	void storeMasterList();

	//generates a report for all students with absences>=minAbsences
	//@param minAbsences - -1 means a report with all students (even ones with no absences)
	void generateReport(int minAbsences);
};
Menu::Menu() {
	list = *(new List<Data>());
}

void Menu::displayMenu() {
	int input = 1;
	//input loop
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
			//2 options for generating the report
			while (input2 <= 0 || input2 >= 3) {
				cout << "Enter an option:\n1.Generate a report for all students\n2.Generate a report with students that have at least n absences\n";
				cin >> input2;
			}
			if (input2 == 1)
				generateReport(-1);
			else {
				//generating a report for students with at least n absences
				while (true) {
					cout << "Enter a minimum number of absences to generate a report from: ";
					cin >> input2;
					if (input2 >= 0)
						break;
				}
				generateReport(input2);
			}
		}
		system("cls");
	}
	courses.close();
	master.close();
}

void Menu::markAbsences() {
	system("cls");
	//running through the list
	Node<Data> *curr(list.getHead());
	while (curr != nullptr) {
		//getting the current date
		Data d = curr->getData();
		time_t t = time(0);
		struct tm *now = localtime(&t);
		string date = to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + "/" + to_string(now->tm_year + 1900);
		int input = -1;
		//checking if the student was absent today
		while (input <= -1 || input >= 2) {
			cout << "Was " << d.name << " absent today " << date << "?\n1 for yes, 0 for no: ";
			cin >> input;
			if (input == 1 || input == 2)
				break;
		}
		//adding the absence to the stack
		if (input == 1) {
			d.addAbscence(date);
			d.setNAbsences(d.getNAbsences() + 1);
		}
		//running through the list and resetting the data
		curr->setData(d);
		curr = curr->getNext();

		system("cls");
	}
	system("cls");
}
void Menu::readCourseList() {
	courses.open("classList.csv");
	char line[300];
	//resetting the list (odd things will happen when trying to read multiple files at the same time)
	list = *(new List<Data>());
	//discarding the first line
	courses.getline(line, 300);
	//running through the file
	while (!courses.eof()) {
		courses.getline(line, 300);
		//last line check
		if (line[0] == '\n'||line[0]=='\0')
			break;
		//getting the student # and ID
		int n = atoi(strtok(line, ",")), ID = atoi(strtok(NULL, ","));
		//special case for the name (have to get the quotes around it)
		string name = strtok(NULL, ",");
		name.append(",");
		name.append(strtok(NULL, ","));
		//getting the rest of the data
		string email = strtok(NULL, ",");
		string units = strtok(NULL, ",");
		string program = strtok(NULL, ",");
		string level = strtok(NULL, "\n");
		//inserting the data into the list
		Data temp(n,ID, name, email, units, program, level,0);
		list.insertAtFront(temp);
	}
	courses.close();
}

void Menu::storeMasterList() {
	master.close();
	master.open("masterList.csv", fstream::out);
	//running through the list
	Node<Data> *curr = list.getHead();
	//first line for the marker
	master << ",ID,Name,Email,Units,Program,Level,Num Absences,Date of Absences\n";
	for (int i = 1; curr != nullptr; i++) {
		Data temp = curr->getData();
		//writing the data to the file
		master << i << "," << temp.getID() << "," << temp.name << "," << temp.email << "," << temp.units << "," << temp.major << "," << temp.level << "," << temp.getNAbsences();
		//running through the stack until the end is reached (to write all the absences to the file)
		Stack s = temp.getStack();
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
	//making a new list
	list = *(new List<Data>());
	//running through the file
	while (!master.eof()) {
		master.getline(line, 300);
		if (line[0] == '\n'||line[0]=='\0')
			break;
		int n = atoi(strtok(line, ",")), ID = atoi(strtok(NULL, ","));
		//special case for the name
		string name = strtok(NULL, ",");
		name.append(",");
		name.append(strtok(NULL, ","));
		//getting the rest of the fields
		string email = strtok(NULL, ",");
		string units = strtok(NULL, ",");
		string program = strtok(NULL, ",");
		string level = strtok(NULL, ",");
		int nAbsences = atoi(strtok(NULL, ","));
		Data temp(n, ID, name, email, units, program, level, nAbsences);
		//getting all the absences and adding it to the stack in reverse order (latest absence will be on the top of the stack)
		if (nAbsences >= 1) {
			string *dates = new string[nAbsences];
			for (int i = 0; i < nAbsences - 1; i++) {
				dates[i] = strtok(NULL, ",");
			}
			//special case for the last absence
			dates[nAbsences - 1] = strtok(NULL, "\n");
			//adding the absence dates in reverse order
			for (int i = nAbsences - 1; i >= 0; i--)
				temp.addAbscence(dates[i]);
		}
		//adding the data to the linked 
		list.insertAtFront(temp);
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