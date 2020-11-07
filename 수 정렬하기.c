#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, number[1001], swap;
	scanf("%d", &input);
	for (int i = 0; i < input; i++) {
		scanf("%d", &number[i]);
	}
	for (int i = 0; i < input; i++) {
		for (int a = i + 1; a < input; a++) {
			if (number[i] > number[a]) {
				swap = number[a];
				number[a] = number[i];
				number[i] = swap;
			}
		}
	}
	for (int i = 0; i < input; i++) {
		printf("%d\n", number[i]);
	}
}