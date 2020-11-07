#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, array[246913] = { 1,1,0, }, origin, count = 0;
	for (int k = 1; k <= 246913; k++) {
		origin = k;
		while (array[k] != 0) {
			k++;
		}
		for (int i = 2; k * i <= 246913; i++) {
			array[k * i]++;
		}
		k = origin;
	}
	while (1) {
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		else {
			for (int i = input+1; i <= 2 * input; i++) {
				if(array[i] == 0) {
					count++;
				}
			}
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}