#include "stacks.h"
int main(void) {
	Stack s = { NULL };
	char str[4] = "cat";
	Data temp = { '\0' };
	puts(str);
	for (int i = 0; i < strlen(str); i++) {
		temp.item = *(str + i);
		push(&s, temp);
	}
	for (int i = 0; !isEmpty(s); i++) {
		temp = peek(s);
		pop(&s);
		*(str + i) = temp.item;
	}
	puts(str);
	return 0;
}