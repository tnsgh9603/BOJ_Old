#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input1, input2, hundred1, ten1, one1, hundred2, ten2, one2, new_input1, new_input2;
	scanf("%d", &input1);
	scanf("%d", &input2);
	one1 = input1 % 10;
	ten1 = (input1 / 10) % 10;
	hundred1 = input1 / 100;
	one2 = input2 % 10;
	ten2 = (input2 / 10) % 10;
	hundred2 = input2 / 100;
	new_input1 = one1 * 100 + ten1 * 10 + hundred1;
	new_input2 = one2 * 100 + ten2 * 10 + hundred2;
	if (new_input1 > new_input2) {
		printf("%d", new_input1);
	}
	else {
		printf("%d", new_input2);
	}
	return 0;
}