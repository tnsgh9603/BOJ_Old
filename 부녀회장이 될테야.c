#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int T, k, n, sum;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &k);
		scanf("%d", &n);
		int array[15][15] = { 0, };
		for (int i = 1; i <= 14; i++) {
			array[1][i] = i * (i + 1) / 2;
		}
		for (int q = 2; q <= 14; q++) {
			for (int w = 1; w <= 14; w++) {
				sum = 0;
				for (int e = 1; e <= w; e++) {
					sum = sum + array[q - 1][e];
				}
				array[q][w] = sum;
			}
		}
		printf("%d\n", array[k][n]);
	}
	return 0;
}