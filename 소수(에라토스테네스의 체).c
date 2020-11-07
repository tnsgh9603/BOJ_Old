#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input1, input2, array[10001] = { 1,1,0, }, sum = 0, count = 0, origin;
	for (int k = 1; k <= 100;k++) {
		origin = k;
		while (array[k] != 0) {
			k++;
		}
		for (int i = 2; k * i <= 10000; i++) {
			array[k * i]++;
		}
		k = origin;
	}
	scanf("%d", &input1);
	scanf("%d", &input2);
	int least = input1;
	for (int i = input1; i <= input2; i++) {
		if (array[i] == 0) {
			sum = sum + i;
			count++;
			if (count == 1) {
				least = i;
				count++;
			}
		}
	}
	if (count == 0) {
		printf("-1");
	}
	else {
		printf("%d\n", sum);
		printf("%d", least);
	}	
	return 0;
}