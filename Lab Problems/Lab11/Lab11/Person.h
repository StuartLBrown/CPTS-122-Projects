#include <iostream>
#include <string>
#pragma once
using std::string;
using std::ostream;
using std::istream;
using std::endl;
using std::cout;

class Person {
protected:
	string name, gender;
	int age, height;
public:
	Person(string _name = "", string _gender = "", int _age = 0, int _height = 0) {
		name = _name;
		gender = _gender;
		age = _age;
		height = _height;
	}
	Person(const Person &p) {
		age = p.age;
		height = p.height;
		name = p.name;
		gender = p.gender;
	}
	Person operator=(const Person &lhs) {
		return Person(lhs);
	}

	void setName(string newName) { name = newName; }
	void setGender(string newGender) { gender = newGender; }
	void setAge(int newAge) { age = newAge; }
	void setHeight(int newHeight) { height = newHeight; }

	string getName() const { return name; }
	string getGender() const { return gender; }
	int getAge() const { return age; }
	int getHeight() const { return height; }


	friend ostream &operator<<(ostream &lhs, const Person &rhs);
	friend istream &operator >> (istream &lhs, Person &rhs);
};

ostream &operator<<(ostream &lhs, const Person &rhs) {
	lhs << rhs.name << " has a height of " << rhs.height << " inches, is " << rhs.age << " years old, and is " << rhs.gender << endl;
	return lhs;
}
istream &operator >> (istream &lhs, Person &rhs) {
	cout << "Name: ";
	lhs >> rhs.name;
	cout << "Gender: ";
	lhs >> rhs.gender;
	cout << "Height (in inches): ";
	lhs >> rhs.height;
	cout << "Age: ";
	lhs >> rhs.age;
	return lhs;
}