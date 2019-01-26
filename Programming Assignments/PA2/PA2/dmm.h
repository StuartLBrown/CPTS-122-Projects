#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int mins;
	int secs;
}Duration;
typedef struct {
	char artist[15];
	char album[25];
	char title[15];
	char genre[15];
	Duration duration;
	int timesPlayed;
	int rating;
}Record;
typedef struct node {
	struct node *prev;
	struct node *next;
	Record song;
}Node;
void menu(FILE *infile);
Node *makeNode(Record data);
int load(FILE *infile, Node **list);
int store(FILE *outfile, Node *list);
void display(Node *list);
void edit(Node **list);
void rate(Node **list);
void play(Node *list);
void exit(Node *list, FILE *outfile);
int insertAtFront(Node **list, Record data);
void printList(Node *list);