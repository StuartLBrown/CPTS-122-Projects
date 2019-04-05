#include "Register.h"
int main(void) {
	Student s("Temp", "male", 10, 60, 0, 0);
	Register r(&s,1);
	r.registerClass();
	return 0;
}