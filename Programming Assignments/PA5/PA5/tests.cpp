#include "Tests.h"
void Tests::testEnqueueEmpty() {
	Queue queue(nullptr);
	Data temp(1, 1, 1);
	queue.enqueue(temp);
	if (queue.getHead()->getData()->getSTime() == temp.getSTime()&&queue.getHead()->getData()->getSTime()==temp.getSTime())
		cout << "Enqueue empty test success!\n";
	else
		cout << "Enqueue empty test failed\n";
}
void Tests::testEnqueueOneNode() {
	Queue queue(nullptr);
	Data temp(1, 1, 1), temp2(2,2,2);
	queue.enqueue(temp);
	queue.enqueue(temp2);
	if (queue.getTail()->getData()->getSTime() == temp2.getSTime()&&queue.getHead()->getData()->getSTime() != temp2.getSTime())
		cout << "Enqueue one node test success!\n";
	else
		cout << "Enqueue one node test failed\n";
}
void Tests::testDequeueOneNode() {
	Queue queue(nullptr);
	Data *temp = new Data(1, 1, 1);
	queue.enqueue(*temp);
	Data temp2 = queue.dequeue();
	if (queue.isEmpty() && temp->getSTime() == temp2.getSTime())
		cout << "Dequeue one node test success!\n";
	else
		cout << "Dequeue one node test failed\n";
}
void Tests::testDeqeueTwoNodes() {
	Queue queue(nullptr);
	Data temp(1, 1, 1), temp2(2,2,2);
	queue.enqueue(temp);
	queue.enqueue(temp2);
	Data temp3 = queue.dequeue();
	if (!queue.isEmpty() &&queue.getHead()==queue.getTail()&& temp.getSTime() == temp3.getSTime())
		cout << "Dequeue two nodes test success!\n";
	else
		cout << "Dequeue two nodes test failed\n";
}
void Tests::test24Hours() {
	runSimulation(1440);
	cout << "24 hour simulation test success!";
}