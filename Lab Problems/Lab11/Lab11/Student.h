#include "Person.h"
#pragma once
typedef struct {
	string cName;
	int credits;
	double grade;
}CourseStudent;
class Student : public Person {
private:
	CourseStudent *courses;
	int numCourses;
	int tCredits;
public:
	Student(string _name, string _gender, int _age, int _height, int _numCourses, int _totalCredits) : Person(_name,_gender,_age,_numCourses) {
		courses = new CourseStudent[100];
		numCourses = _numCourses;
		tCredits = _totalCredits;
	}
	Student(const Student &s) : Person(s) {
		courses = s.courses;
		numCourses = s.numCourses;
		tCredits = s.tCredits;
	}
	CourseStudent *getCourse() const { return courses; }
	int getNumCourses() const { return numCourses; }
	int getTotalCredits() const { return tCredits; }

	void addCourse(string name, int credits, double currentGrade) {
		CourseStudent c;
		c.cName = name;
		c.credits = credits;
		c.grade = currentGrade;
		courses[numCourses] = c;
		numCourses++;
	}
	void addCourse(CourseStudent &c) {
		courses[numCourses] = c;
		numCourses++;
	}

	void setNumCourses(int newNumCourses) { numCourses = newNumCourses; }
	void setTotalCredits(int newTotalCredits) { tCredits = newTotalCredits; }

	int computeTotalCredits() const{
		int total = 0;
		for (int i = 0; i < numCourses; i++)
			total += courses[i].credits;
		return total;
	}

	double computeGPA() const{
		double total = 0;
		int tCredits = computeTotalCredits();
		if (tCredits == 0)
			return 0;
		for (int i = 0; i < numCourses; i++) {
			total += courses[i].credits*courses[i].grade;
		}
		return total / tCredits;
	}

	Student operator=(const Student &s) {
		return Student(s);
	}

	friend ostream &operator<<(ostream &lhs, const Student &s) {
		lhs << s.name << " has a height of " << s.height << " inches, is " << s.age << " years old, and is " << s.gender << endl;
		lhs << " took classes:\n";
		for (int i = 0; i < s.getNumCourses(); i++) {
			lhs << s.courses->cName << " for " << s.courses->credits << " credits and has a " << s.courses->grade << " grade in it\n";
		}
		lhs << "They also have taken a total of " << s.getNumCourses() << " courses for a total credits of " << s.getTotalCredits() << " and has a GPA of " << s.computeGPA();
		return lhs;
	}
	friend istream &operator >> (istream &lhs, Student &s) {
		cout << "Name: ";
		lhs >> s.name;
		cout << "Gender: ";
		lhs >> s.gender;
		cout << "Height (in inches): ";
		lhs >> s.height;
		cout << "Age: ";
		lhs >> s.age;
		while (true) {
			int input = 0;
			cout << "Enter a course name: ";
			CourseStudent c;
			lhs >> c.cName;
			cout << "Enter the number of credits for the course: ";
			lhs >> c.credits;
			cout << "Enter the grade in that course(in percentage): ";
			lhs >> c.grade;
			s.addCourse(c);
			cout << "Enter 1 to add another course, 0 to stop: ";
			lhs>> input;
			if (input != 1)
				break;
		}
		return lhs;
	}
};