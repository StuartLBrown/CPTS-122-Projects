#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char item;
}Data;
typedef struct node {
	Data d;
	struct node *next;
}Node;
typedef struct {
	Node *top;
}Stack;
Node *makeNode(Data d);
int push(Stack *s, Data d);
//stack must not be empty
void pop(Stack *s);
//stack must not be empty
Data peek(Stack s);
int isEmpty(Stack s);