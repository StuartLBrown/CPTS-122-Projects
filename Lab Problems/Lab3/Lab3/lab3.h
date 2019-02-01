#ifndef LAB3_H
#define LAB3_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	double d;
}Data;
typedef struct node {
	struct node *next;
	Data d;
}Node;
typedef struct {
	Node *head;
}Stack;
int isEmpty(Stack s);
int push(Stack *s, Data data);
void pop(Stack *s);
Data peek(Stack s);
//precondition p1 must already be set up with the number of disks passed in
void towerOfHanoi(Stack p1, Stack p2, Stack p3, int numDisks);
void printPole(Stack p1, Stack p2, Stack p3);
void swapStacks(Stack *dest, Stack *source, int *moves);
void makeMove(Stack *a, Stack *b, int *moves);
#endif