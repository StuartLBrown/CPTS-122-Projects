#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
//should almost always use structs when dealing with linked lists/ data structures
typedef struct {
	int data;
}Data;
//struct for the linked list
typedef struct node {
	Data data;
	struct node *next;
}Node;
void initList(Node **head);
Node *makeNode(Data item);
int insertAtFront(Node **head, Data newItem);
void printList(Node *head);
int deleteItem(Node **head, Data item);
int isEmpty(Node *head);
//smallest to largest
int insertInOrder(Node **head, Data item);
#endif // !LINKEDLIST_H