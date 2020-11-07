#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, sum = 0, copy;
	scanf("%d", &input);
	int least = input;
	for (int i = 1; i <= input; i++){
		copy = i;
		while (i > 0) {
			sum = sum + (i % 10);
			i = i / 10;
		}
		sum = copy + sum;
		if (sum == input && least > copy) {
			least = copy;
		}
		i = copy;
		sum = 0;
	}
	if (least == input) {
		printf("0");
	}
	else {
		printf("%d", least);
	}
	return 0;
}