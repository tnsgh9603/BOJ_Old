#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, input1, input2, count = 0, least, i, sum = 0, count1 = 0;
	scanf("%d", &input1);
	scanf("%d", &input2);
	least = input1;
	for (int k = input1; k <= input2; k++) {
		if (k == 2) {
			least = 2;
			count++;
			sum = sum + 2;
		}
		else {
			for (i = 2; i < k; i++) {
				if (k % i == 0) {
					break;
				}
				if (i == k - 1) {
					count++;
					if (count == 1) {
						least = k;
					}
					sum = sum + k;
				}
			}
		}
	}
	if (count == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", sum);
		printf("%d\n", least);
	}
	return 0;
}