#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, score = 0, sum = 0;
	scanf("%d", &number);
	for (int i = 1; i <= number; i++) {
		char array[81] = { 0, };
		scanf("%s", array);
		if (array[0] == 'O') {
			score = 1;
			sum = sum + score;
		}
		for (int i = 1; i < 80; i++) {
			if (array[i] == 'O' && array[i - 1] == 'O') {
				score++;
				sum = sum + score;
			}
			else if (array[i] == 'O' && array[i - 1] != 'O') {
				score = 1;
				sum = sum + score;
			}
			else if (array[i] != 'O') {
				score = 0;
			}
		}
		printf("%d\n", sum);
		score = 0;
		sum = 0;
	}
	return 0;
}