#include "lab3.h"
int isEmpty(Stack s) {
	return (s.head == NULL);
}
int push(Stack *s, Data data) {
	if (!isEmpty(*s)) {
		Node *temp = (Node*)malloc(sizeof(Node));
		if (temp != NULL) {
			temp->d = data;
			temp->next = s->head;
			s->head = temp;
			return 1;
		}
	}
	else {
		Node *temp = (Node*)malloc(sizeof(Node));
		if (temp != NULL) {
			temp->d = data;
			temp->next = NULL;
			s->head = temp;
			return 1;
		}
	}
	return 0;
}
void pop(Stack *s) {
	if (!isEmpty(*s)) {
		Node *temp = s->head;
		if (temp->next == NULL)
			s->head = NULL;
		else {
			s->head = temp->next;
		}
		free(temp);
	}
}
Data peek(Stack s) {
	if (!isEmpty(s)) {
		return s.head->d;
	}
	Data d = { 0 };
	return d;
}
void towerOfHanoi(Stack source, Stack aux, Stack dest, int numDisks) {
	int numMoves = 0;
	if (numDisks % 2 == 0) {
		while (!isEmpty(source) || !isEmpty(aux)) {
			makeMove(&source, &aux, &numMoves);
			//printPole(source, aux, dest);
			if (!isEmpty(source) || !isEmpty(aux)) {
				makeMove(&source, &dest, &numMoves);
				//printPole(source, aux, dest);
			}
			if (!isEmpty(source) || !isEmpty(aux)) {
				makeMove(&aux, &dest, &numMoves);
				//printPole(source, aux, dest);
			}
		}
	}
	else {
		while (!isEmpty(source) || !isEmpty(aux)) {
			makeMove(&source, &dest, &numMoves);
			//printPole(source, aux, dest);
			if (!isEmpty(source) || !isEmpty(aux)) {
				makeMove(&source, &aux, &numMoves);
				//printPole(source, aux, dest);
			}
			if (!isEmpty(source) || !isEmpty(aux)) {
				makeMove(&aux, &dest, &numMoves);
				//printPole(source, aux, dest);
			}
		}
	}
	printf("Done in %d moves\n",numMoves);
}
void makeMove(Stack *a, Stack *b, int *moves) {
	if (isEmpty(*b))
		swapStacks(b, a, moves);
	else if (isEmpty(*a))
		swapStacks(a, b, moves);
	else if (peek(*a).d < peek(*b).d)
		swapStacks(b, a, moves);
	else if (peek(*b).d < peek(*a).d)
		swapStacks(a, b, moves);
}
//precondition source cannot be empty
void swapStacks(Stack *dest, Stack *source, int *moves) {
	Data temp = peek(*source);
	pop(source);
	push(dest, temp);
	(*moves)++;
}
void printPole(Stack p1, Stack p2, Stack p3) {
	if (!isEmpty(p1)) {
		Data t = peek(p1);
		printf("Post Number 1 has a disk of diameter %.0lf on top | ", t.d);
	}
	if (!isEmpty(p2)) {
		Data t = peek(p2);
		printf("Post Number 2 has a disk of diameter %.0lf on top | ", t.d);
	}
	if (!isEmpty(p3)) {
		Data t = peek(p3);
		printf("Post Number 3 has a disk of diameter %.0lf on top", t.d);
	}
	printf("\n");
}