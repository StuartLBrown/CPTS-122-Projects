#include "lab3.h"
#include "testS.h"
void testIsEmpty(void){
	Stack s = { NULL };
	Stack t;
	Data d = { .21 };
	push(&t, d);
	if(isEmpty(s)&&!isEmpty(t))
		printf("Passed isEmpty");
	else
		printf("Failed isEmpty");
}
void testPush(void) {
	Stack s = { NULL };
	Data t = { 1.1 };
	Data u = { 2.2 };
	push(&s, t);
	push(&s, u);
	if (s.head->d.d == u.d&&s.head->next->d.d == t.d)
		printf("Passed testPush");
	else
		printf("Failed testPush");
}
void testPeek(void) {
	Stack s = { NULL }, t = { NULL };
	Data d = { 10.1 };
	push(&t, d);
	if (peek(s).d == 0 && peek(t).d == d.d)
		printf("Passed testPeek");
	else
		printf("Failed testPeek");
}
void testPop(void) {
	Stack t = { NULL }, s = { NULL };
	Data d = { 10.1 };
	push(&t, d);
	push(&s, d);
	push(&s, d);
	pop(&t);
	pop(&s);
	if (s.head->d.d = d.d)
		printf("Passed testPop");
	else
		printf("Failed testPop");
}