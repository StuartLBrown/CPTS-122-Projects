#include "queues.h"
int main(void) {
	Queue q("temp");
	q.enqueue("temp2");
	q.enqueue("temp3");
	std::cout << q;
	return 0;
}