#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, input, count = 0;
	scanf("%d", &input);
	for (int i = 1; i <= input; i++) {
		scanf("%d", &number);
		if (number == 1) {
		}
		else if (number == 2) {
			count++;
		}
		else {
			for(int i = 2; i < number; i++) {
				if (number % i == 0) {
					break;
				}
				if (i == number-1) {
					count++;
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}