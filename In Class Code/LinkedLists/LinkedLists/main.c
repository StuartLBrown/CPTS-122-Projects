#include "LinkedList.h"
int main(int argc, char *argv[]) {
	Node *phead = NULL;//list is empty
	Data data1 = { 1111 }, data2 = { 2222 };
	initList(&phead);
	insertAtFront(&phead, data1);
	insertAtFront(&phead, data2);
	printList(phead);
	return 0;
}