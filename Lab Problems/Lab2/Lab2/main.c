#include "lab2.h"
int main(void) {
	Contact temp = {"Test1","32803290","@jkdsljsdlk","Temp"}, temp2 = { "Uest1","32803290","@jkdsljsdlk","Temp" },temp3 = { "Sest1","32803290","@jkdsljsdlk","Temp" }, temp4 = { "Sest1","32803290","@testCase","Temp" };
	FILE *infile = fopen("data.csv", "r"), *outfile = fopen("data2.csv","w");
	Node *list = NULL;
	list = makeNode(temp);
	insertContactInOrder(&list, temp2);
	insertContactInOrder(&list, temp3);
	printList(list);
	printf("\n");
	loadContacts(infile, &list);
	printList(list);
	storeContacts(outfile, list);
	return 0;
}