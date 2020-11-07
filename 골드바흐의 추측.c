#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, input, array[10001] = { 1,1,0, }, origin, answer1 = 0, answer2 = 0, least;
	for (int k = 1; k <= 10000; k++) {
		origin = k;
		while (array[k] != 0) {
			k++;
		}
		for (int i = 2; k * i <= 10000; i++) {
			array[k * i]++;
		}
		k = origin;
	}
	scanf("%d", &number);
	for (int i = 1; i <= number; i++) {
		scanf("%d", &input);
		least = input;
		for (int k = 1; k <= input / 2; k++) {
			if (array[k] == 0 && array[input - k]==0) {
				if (input - 2 * k < least) {
					least = input - 2 * k;
					answer1 = k;
					answer2 = input - k;
				}
			}
		}
		printf("%d %d\n", answer1, answer2);
	}
	return 0;
}