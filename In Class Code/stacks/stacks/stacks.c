#include "stacks.h"
Node *makeNode(Data d) {
	Node *temp = (Node*)malloc(sizeof(Node));
	if (temp != NULL) {
		temp->d = d;
		temp->next = NULL;
	}
	return temp;
}
int push(Stack *s, Data d) {
	Node *temp = makeNode(d);
	int success = 0;
	if (temp != NULL) {
		temp->next = s->top;
		s->top = temp;
		return 1;
	}
	return 0;
}
void pop(Stack *s) {
	Node *temp = s->top;
	s->top = s->top->next;
	free(temp);
}
Data peek(Stack s) {
	return s.top->d;
}
int isEmpty(Stack s) {
	if (&s == NULL)
		return 1;
	return 0;
}