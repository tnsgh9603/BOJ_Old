#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	int* array = (int*)malloc(sizeof(int) * 1000001);
	array[1000001] = { 1,1,0, };
	int input1, input2, origin;
	for (int k = 1; k <= 1000000; k++) {
		origin = k;
		while (array[k] != 0) {
			k++;
		}
		for (int i = 2; (k * i) <= 1000000; i++) {
			array[k * i]++;
		}
		k = origin;
	}
	scanf("%d %d", &input1, &input2);
	for (int i = input1; i <= input2; i++) {
		if (array[i] == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}