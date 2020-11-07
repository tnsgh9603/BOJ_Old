#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, count = 0, hundred, ten, one;
	scanf("%d", &number);
	for (int i = 1; i <= number;i++) {
		if (i < 100) {
			count++;
		}
		if (i >= 100) {
			one = i % 10;
			ten = (i / 10) % 10;
			hundred = i / 100;
			if (hundred - ten == ten - one) {
				count++;
			}
		}
	}
	printf("%d" ,count);
	return 0;
}