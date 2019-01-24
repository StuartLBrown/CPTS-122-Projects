#include "lab2.h"
Node *makeNode(Contact newData) {
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	if (temp != NULL) {
		temp->data = newData;
		temp->next = NULL;
	}
	return temp;
}
Boolean insertContactInOrder(Node **list, Contact data) {
	if (*list == NULL) {
		*list = makeNode(data);
		if (*list == NULL)
			return FALSE;
	}
	else {
		Node *prev = NULL,*curr = *list, *next = (*list)->next;
		while (curr != NULL&&next!=NULL&&strcmp(curr->data.name, data.name) < 0) {
			prev = curr;
			curr = next;
			next = next->next;
		}
		if (curr == NULL) {
			curr = makeNode(data);
		}
		if (prev == NULL&&next!=NULL) {
			prev = makeNode(data);
			prev->next = *list;
			*list = prev;
		}
		else if (strcmp(curr->data.name, data.name) < 0) {
			prev = makeNode(data);
			curr->next = prev;
			prev->next = next;
		}
		else if (strcmp(curr->data.name, data.name) > 0) {
			next = makeNode(data);
			next->next = curr;
			prev->next = next;
		}
		if (curr == NULL)
			return FALSE;
	}
	return TRUE;
}
Boolean deleteContact(Node **list, Contact data) {
	if (*list == NULL)
		return FALSE;
	else {
		Node *prev = NULL;
		Node *curr = *list;
		Node *next = curr->next;
		while (next != NULL&&curr != NULL&&strcmp(curr->data.name, data.name) != 0) {
			prev = curr;
			curr = next;
			next = curr->next;
		}
		if (prev == NULL) {
			*list = next;
			free(curr);
			return TRUE;
		}
		if (strcmp(curr->data.name, data.name) == 0) {
			prev->next = next;
			free(curr);
			return TRUE;
		}
	}
	return FALSE;
}
Boolean editContact(Node *list, Contact data) {
	if (list == NULL)
		return FALSE;
	else {
		while (list != NULL&&strcmp(list->data.name, data.name) != 0)
			list = list->next;
		if (list != NULL) {
			list->data = data;
			return TRUE;
		}
	}
	return FALSE;
}
Boolean loadContacts(FILE *file, Node **list) {
	char temp[500];
	fgets(temp, 500, file);
	while (!feof(file)) {
		char line[500];
		fgets(line, 500, file);
		Contact temp = { NULL,NULL,NULL,NULL };
		strcpy(temp.name,strtok(line, ","));
		strcpy(temp.phone, strtok(NULL, ","));
		strcpy(temp.email, strtok(NULL, ","));
		strcpy(temp.title, strtok(NULL, ","));
		if (temp.email == NULL || temp.name == NULL || temp.phone == NULL || temp.title == NULL)
			return FALSE;
		Boolean temp2 = insertContactInOrder(list, temp);
		if (temp2 == FALSE)
			return temp2;
	}
	return TRUE;
}
Boolean storeContacts(FILE *file, Node *list) {
	if (list == NULL)
		return FALSE;
	fputs("Name,Phone,Email,Title,(Leave Blank)\n", file);
	while (list != NULL) {
		fprintf(file, "%s,%s,%s,%s,\n", list->data.name, list->data.phone, list->data.email, list->data.title);
		list = list->next;
	}
	return TRUE;
}
void printList(Node *list) {
	Node *temp = list;
	while (temp != NULL) {
		printf("Name: %s\nPhone: %s\nEmail: %s\nTitle: %s\n", temp->data.name, temp->data.phone, temp->data.email, temp->data.title);
		temp = temp->next;
	}
}