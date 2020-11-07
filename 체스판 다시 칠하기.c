#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input1, input2, count = 0, count2 = 0, least, count3 = 0;
	char array[51][51];
	scanf("%d %d", &input1, &input2);
	for (int i = 0; i < input1; i++) {
		scanf("%s", array[i]);
	}
	for (int i = 0; i < input1 - 7; i++) {
		for (int k = 0; k < input2 - 7; k++) {
			for (int q = i; q <= i + 6; q = q + 2) {
				for (int w = k; w <= k + 6; w = w + 2) {
					if (array[q][w] != 'B') {
						count++;
					}
				}
			}
			for (int q = i; q <= i + 6; q = q + 2) {
				for (int w = k + 1; w <= k + 7; w = w + 2) {
					if (array[q][w] != 'W') {
						count++;
					}
				}
			}
			for (int q = i + 1; q <= i + 7; q = q + 2) {
				for (int w = k; w <= k + 6; w = w + 2) {
					if (array[q][w] != 'W') {
						count++;
					}
				}
			}
			for (int q = i + 1; q <= i + 7; q = q + 2) {
				for (int w = k + 1; w <= k + 7; w = w + 2) {
					if (array[q][w] != 'B') {
						count++;
					}
				}
			}
			for (int q = i; q <= i + 6; q = q + 2) {
				for (int w = k; w <= k + 6; w = w + 2) {
					if (array[q][w] != 'W') {
						count3++;
					}
				}
			}
			for (int q = i; q <= i + 6; q = q + 2) {
				for (int w = k + 1; w <= k + 7; w = w + 2) {
					if (array[q][w] != 'B') {
						count3++;
					}
				}
			}
			for (int q = i + 1; q <= i + 7; q = q + 2) {
				for (int w = k; w <= k + 6; w = w + 2) {
					if (array[q][w] != 'B') {
						count3++;
					}
				}
			}
			for (int q = i + 1; q <= i + 7; q = q + 2) {
				for (int w = k + 1; w <= k + 7; w = w + 2) {
					if (array[q][w] != 'W') {
						count3++;
					}
				}
			}
			count2++;
			if (count2 == 1) {
				if (count3 > count){
					least = count;
				}
				else {
					least = count3;
				}
			}
			else {
				if (least > count&&count<count3) {
					least = count;
				}
				if (least > count3 && count > count3) {
					least = count3;
				}
			}
			count = 0;
			count3 = 0;
		}
	}
	printf("%d", least);
	return 0;
}