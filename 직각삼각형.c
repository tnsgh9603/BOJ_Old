#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input1, input2, input3, big, middle, small;
	while (1) {
		scanf("%d %d %d", &input1, &input2, &input3);
		if (input1 == 0 && input2 == 0 && input3 == 0) {
			break;
		}
		if (input1 >= input2 && input1 >= input3) {
			big = input1;
			middle = input2;
			small = input3;
		}
		else if (input2 >= input3 && input2 >= input1) {
			big = input2;
			middle = input3;
			small = input1;
		}
		else if (input3 >= input1 && input3 >= input2) {
			big = input3;
			middle = input1;
			small = input2;
		}
		if (big * big == middle * middle + small * small) {
			printf("right\n");
		}
		else {
			printf("wrong\n");
		}
	}
	return 0;
}