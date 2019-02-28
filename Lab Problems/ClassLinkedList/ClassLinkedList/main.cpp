#include "ListApp.h"

int main(void)
{
	List l1;
	l1.insertAtEnd(10);
	l1.insertAtEnd(5);
	l1.insertAtEnd(15);
	l1.deleteAtEnd();
	ListApp app;

	app.runApp();

	return 0;
}