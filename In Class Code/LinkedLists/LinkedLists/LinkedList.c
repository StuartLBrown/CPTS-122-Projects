#include "LinkedList.h"
void initList(Node **head) {
	head = NULL;
}
Node *makeNode(Data item) {
	Node *pMem = NULL;
	pMem = (Node*)malloc(sizeof(Node));
	if (pMem != NULL) {
		pMem->data = item;
		pMem->next = NULL;
	}
	return pMem;
}
int insertAtFront(Node **head, Data item) {
	Node *pMem = NULL;
	int success = 0;
	pMem = makeNode(item);
	if (pMem != NULL) {
		success = 1;
		pMem->next = pMem;
	}
	return success;
}