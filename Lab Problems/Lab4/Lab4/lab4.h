#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	struct node *next;
	int data;
}Node;

char *copyStrtoHeap(char *str);
Node *mergeLists(Node *lists);