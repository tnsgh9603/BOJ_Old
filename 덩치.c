#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int person_number, weight[51] = { 0, }, height[51] = { 0, }, count[51] = { 0, };
	scanf("%d", &person_number);
	for (int i = 1; i <= person_number; i++) {
		scanf("%d %d", &weight[i], &height[i]);
	}
	for (int i = 1; i <= person_number; i++) {
		for (int k = 1; k <= i; k++) {
			if (weight[i] < weight[i - k] && height[i] < height[i - k]) {
				count[i]++;
			}
		}
		for (int q = 1; q <= person_number - i; q++) {
			if (weight[i] < weight[i + q] && height[i] < height[i + q]) {
				count[i]++;
			}
		}
	}
	for (int i = 1; i <= person_number; i++) {
		printf("%d ", count[i] + 1);
	}
	return 0;
}