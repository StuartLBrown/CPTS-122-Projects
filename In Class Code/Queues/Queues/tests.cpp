#include "tests.h"
void Tests::testInsertEmpty() {
	Queue q;
	bool success = false;
	string s1 = "test";
	success = q.enqueue(s1);
	if (success) {
		cout << "Allocated space" << endl;

	}
}