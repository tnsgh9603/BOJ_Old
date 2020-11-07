#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, M, card_number, array[101] = { 0, }, max = 0;
	scanf("%d %d", &number, &M);
	for (int i = 1; i <= number; i++) {
		scanf("%d", &card_number);
		array[i] = card_number;
	}
	for (int i = 1; i <= number; i++) {
		for (int k = i + 1; k <= number; k++) {
			for (int q = k + 1; q <= number; q++) {
				if (array[i] + array[k] + array[q] <= M && array[i] + array[k] + array[q] > max) {
					max = array[i] + array[k] + array[q];
				}
			}
		}
	}
	printf("%d", max);
	return 0;
}