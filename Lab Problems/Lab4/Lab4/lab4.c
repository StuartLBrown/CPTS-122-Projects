#include "lab4.h"

char *copyStrtoHeap(char *str) {
	char *str2 = (char*)malloc(strlen(str)+1);
	if (str2 == NULL)
		return NULL;
	memcpy(str2, str, strlen(str)+1);
	return str2;
}

Node *mergeLists(Node *list1, Node *list2) {
	if (list1 == NULL&&list2 == NULL)
		return NULL;
	else if (list1 == NULL)
		return list2;
	else if (list2 == NULL)
		return list1;
	else {
		if (list1->data <= list2->data) {
			list1->next = mergeLists(list1->next, list2);
			return list1;
		}
		else {
			list2->next = mergeLists(list1, list2->next);
			return list2;
		}
	}
}
int findLoop(Node *list) {
	Node *fast = list, *slow = list;
	while (fast != NULL&&slow!=NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}
Node *reverseList(Node **list) {
	Node *prev = NULL, *cur = *list, *next=(*list)->next;
	while (cur != NULL) {
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
	return *list;
}