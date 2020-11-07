#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a, b, c, answer;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	if (b >= c) {
		answer = -1;
	}
	else {
		if (a < (c - b)) {
			answer = 1;
		}
		else {
			answer = a / (c - b) +1;
		}
	}
	printf("%d", answer);
	return 0;
}