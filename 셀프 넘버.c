#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int array[10001] = { 1,0, }, a, total_sum;
	for (int i = 1; i < 10000; i++) {
		a = i;
		int sum = 0;
		if (i < 10) {
			array[i * 2]++;
		}
		if (i >= 10) {
			for (; i / 10 >= 1;) {
				sum = sum + (i % 10);
				i /= 10;
				if (i < 10) {
					sum = sum + i;
				}
			}
			sum = sum + a;
			if (sum <= 10000) {
				array[sum]++;
			}
			i = a;
		}
	}
	for (int c = 1; c < 10000; c++) {
		if (array[c] == 0) {
			printf("%d\n", c);
		}
	}
	return 0;
}