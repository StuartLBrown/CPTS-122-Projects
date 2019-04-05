#include "Person.h"
#pragma once
typedef struct {
	string cName;
	int credits;
	double averageGrade;
}CourseTeacher;
class Teacher : public Person {
private:
	CourseTeacher *courses;
	int coursesTaught;
	int tCredits;
public:
	Teacher(string _name="", string _gender="", int _age=0, int _height=0, int _coursesTaught=0, int _totalCredits=0) : Person(_name, _gender, _age, _height) {
		courses = new CourseTeacher[100];
		coursesTaught = _coursesTaught;
		tCredits = _totalCredits;
	}
	Teacher(const Teacher &s) : Person(s) {
		courses = s.courses;
		coursesTaught = s.coursesTaught;
		tCredits = s.tCredits;
	}

	CourseTeacher *getCourse() const { return courses; }
	int getCoursesTought() const { return coursesTaught; }
	int getTotalCredits() const { return tCredits; }

	int computeTotalCredits() const {
		int total = 0;
		for (int i = 0; i < coursesTaught; i++)
			total += courses[i].credits;
		return total;
	}
	double computeAverageGrade()const {
		int total = computeTotalCredits();
		double temp = 0;
		for (int i = 0; i < coursesTaught; i++)
			temp += courses[i].averageGrade*courses[i].credits;
		return total / temp;
	}

	void addCourse(string name, int credits, double averageGrade) {
		CourseTeacher c;
		c.cName = name;
		c.credits = credits;
		c.averageGrade = averageGrade;
		courses[coursesTaught] = c;
		coursesTaught++;
	}

	void addCourse(CourseTeacher &c) {
		courses[coursesTaught] = c;
		coursesTaught++;
	}

	Teacher operator=(const Teacher &t) {
		return Teacher(t);
	}

	friend ostream &operator<<(ostream &lhs, const Teacher &t) {
		lhs << t.name << " has a height of " << t.height << " inches, is " << t.age << " years old, and is " << t.gender << endl;
		lhs << " taught classes:\n";
		for (int i = 0; i < t.getCoursesTought(); i++) {
			lhs << t.courses->cName << " for " << t.courses->credits << " credits and the students have a " << t.courses->averageGrade << " average grade in it\n";
		}
		lhs << "They also have taught a total of " << t.getCoursesTought() << " courses for a total credits of " << t.tCredits << " and has an average GPA of " << t.computeAverageGrade();
	}
	friend istream &operator >> (istream &lhs, Teacher &t) {
		cout << "Name: ";
		lhs >> t.name;
		cout << "Gender: ";
		lhs >> t.gender;
		cout << "Height (in inches): ";
		lhs >> t.height;
		cout << "Age: ";
		lhs >> t.age;
		while (true) {
			int input = 0;
			cout << "Enter a course name: ";
			CourseTeacher c;
			lhs >> c.cName;
			cout << "Enter the number of credits for the course: ";
			lhs >> c.credits;
			cout << "Enter the average grade in that course(in GPA): ";
			lhs >> c.averageGrade;
			t.addCourse(c);
			cout << "Enter 1 to add another course, 0 to stop: ";
			lhs >> input;
			if (input != 1)
				break;
		}
		return lhs;
	}
};