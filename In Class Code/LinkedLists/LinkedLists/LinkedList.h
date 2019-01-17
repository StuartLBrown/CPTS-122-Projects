#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
//should almost always use structs when dealing with linked lists/ data structures
typedef struct {
	int data;
}Data;
//struct for the linked list
typedef struct {
	Data data;
	Node *next;
}Node;
void initList(Node **head);
Node *makeNode(Data item);
int insertAtFront(Node **head, Data newItem);
#endif // !LINKEDLIST_H