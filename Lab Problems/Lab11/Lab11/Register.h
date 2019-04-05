#include "Student.h"
#include "Teacher.h"
#pragma once
using std::cout;
using std::cin;
class Register {
private:
	Student *students;
	Teacher t;
	int numStudents;
public:
	Register(Student *_students=nullptr, int _numStudents=0) {
		std::cin >> t;
		students = _students;
		numStudents = _numStudents;
	}
	void registerClass() {
		for (int i = 0; i < numStudents; i++) {
			int stop = -1;
			Student s = students[i];
			cout << s << endl;
			while (true) {
				for (int j = 0; j < t.getCoursesTought(); j++) {
					CourseTeacher c = t.getCourse()[j];
					cout << j + 1 << ". Name: " << c.cName << " |Credits: " << c.credits << " |Average Grade: " << c.averageGrade << endl;
				}
				cout << "Enter a course to register: ";
				int input = 0;
				cin >> input;
				input -= 1;
				CourseTeacher c = t.getCourse()[input];
				s.addCourse(c.cName, c.credits, 0);
				cout << "1 to add another course, 0 to stop: ";
				cin >> stop;
				if (stop != 1)
					break;
				system("cls");
			}
		}
	}
};
ostream &operator<<(ostream &lhs, CourseTeacher &c) {
	lhs << "Name: " << c.cName << "\nCredits: " << c.credits << "\nAverage Grade: " << c.averageGrade << endl;
	return lhs;
}