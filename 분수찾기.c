#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, left, right;
	scanf("%d", &input);
	if (input == 1) {
		left = 1;
		right = 1;
	}
	else {
		for (int i = 2; i < 14500; i++) {
			if ((i * (i - 1)) / 2 < input && input <= (i * (i + 1)) / 2) {
				if (i % 2 == 0) {
					left = (input - (i * (i - 1) / 2));
					right = i + 1 - left;
				}
				if (i % 2 != 0) {
					right = (input - (i * (i - 1) / 2));
					left = i + 1 - right;
				}
			}
		}
	}
	printf("%d/%d", left, right);
	return 0;
}