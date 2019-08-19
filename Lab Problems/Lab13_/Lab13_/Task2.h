#pragma once
#include <iostream>
using std::cout;
using std::endl;
class Mammal{
public:
	Mammal(void):itsAge(1){}
	~Mammal(void);
	virtual void Move() const { cout << "Mammal moves" << endl; }
	virtual void Speak() const { cout << "Mammal speaks" << endl; }
protected:
	int itsAge;
};

class Dog :public Mammal {
public:
	void Move() const { cout << "Dog moves" << endl; }
	void Speak()const { cout << "Bark" << endl; }
};

class Cat :public Mammal {
public:
	void Move() const { cout << "Cat moves" << endl; }
	void Speak()const { cout << "Meow" << endl; }
};

class Horse :public Mammal {
public:
	void Move() const { cout << "Horse moves" << endl; }
	void Speak()const { cout << "Neigh" << endl; }
};

class GuineaPig :public Mammal {
public:
	void Move() const { cout << "Guinea Pig moves" << endl; }
	void Speak()const { cout << "Weep Weep" << endl; }
};
