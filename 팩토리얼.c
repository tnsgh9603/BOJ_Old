#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int factorial(int a) {
	if (a == 0) {
		return 1;
	}
	else {
		return a * factorial(a - 1);
	}
}
int main() {
	int input;
	scanf("%d", &input);
	printf("%d", factorial(input));
	return 0;
}