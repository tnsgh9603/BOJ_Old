#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fibo(int a) {
	if (a == 1) {
		return 1;
	}
	if (a == 0) {
		return 0;
	}
	else {
		return fibo(a - 1) + fibo(a - 2);
	}
}
int main() {
	int input;
	scanf("%d", &input);
	printf("%d", fibo(input));
	return 0;
}