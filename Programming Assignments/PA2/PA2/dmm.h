#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	int mins;
	int secs;
}Duration;
typedef struct {
	char artist[20];
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
//done
void menu(FILE *infile);

//done
Node *makeNode(Record data);

//done
int load(FILE *infile, Node **list);

//precondition: file doesn't have to be in write mode beforehand, data will be overwritten anyway
//done
int store(FILE *file, Node *list);

//done
void display(Node *list,char *artist);
//done
void edit(Node **list, char *artist);
void rate(Node **list);
void play(Node *list);

//done
int insertAtFront(Node **list, Record data);

void displayRecord(Record r);

void editRecord(Record *r, int attribute);
