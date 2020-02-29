#include "testS.h"
int main(void) {
	/*
	Stack p1 = { NULL }, p2 = { NULL }, p3 = { NULL };
	for (int i = 15; i > 0; i--) {
		Data t = { i };
		push(&p1, t);
	}
	towerOfHanoi(p1, p2, p3, 15);
	*/
	Stack stack = { NULL };
	for (int i = 0; i < 10; i++) {
		Data temp = { i + 1 };
		push(&stack, temp);
	}
	divStack(&stack);
	printf("%.2lf\n", peek(stack).d);
	addAll(&stack);
	printf("%.2lf\n", peek(stack).d);
	return 0;
}