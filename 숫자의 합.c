#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int number, sum = 0, a;
	char number_array[101];
	scanf("%d", &number);
	scanf("%s", number_array);
	for (int i = 0; i < number; i++) {
		sum = sum + (number_array[i]- '0');
	}
	printf("%d", sum);
	return 0;
}