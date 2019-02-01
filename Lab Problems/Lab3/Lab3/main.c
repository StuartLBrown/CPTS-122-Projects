#include "testS.h"
int main(void) {
	Stack p1 = { NULL }, p2 = { NULL }, p3 = { NULL };
	for (int i = 15; i > 0; i--) {
		Data t = { i };
		push(&p1, t);
	}
	towerOfHanoi(p1, p2, p3, 15);
	return 0;
}