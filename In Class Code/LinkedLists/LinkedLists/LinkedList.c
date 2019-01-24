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
		pMem->next = *head;
		*head = pMem;
	}
	return success;
}
void printList(Node *head) {
	if (head != NULL) {
		printf("ID: %d\n", head->data.data);
		printList(head->next);
	}
}
int deleteItem(Node **head, Data item) {
	Node *pTemp = NULL, *pCur = *head;
	int success = 0;
	while (!success&&pCur!=NULL) {
		if (pCur->data.data == item.data) {
			success = 1;
			if (pTemp != NULL) {
				//'delinking' the node that is neeeded for deletion 
				pTemp->next = pCur->next;
			}
			else {//deleting the first item
				(*head)->next = pCur->next;
			}
			//once we find we free it
			free(pCur);
		}
		else {
			pTemp = pCur;
			pCur = pCur->next;
		}
	}
	return success;
}
int isEmpty(Node *head) {
	return head == NULL;
}
int insertInOrder(Node **head, Data item) {
	if (*head == NULL) {
		*head = makeNode(item);
		return head != NULL;
	}
	else {
		Node *prev=NULL, *cur=*head, *mem = NULL;
		int success = 0;
		mem = makeNode(item);
		if (mem != NULL) {
			while (cur != NULL&&cur->data.data < item.data) {

			}
		}
		return success;
	}
}