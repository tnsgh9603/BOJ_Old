#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, sum = 1, output = 1, i;
	scanf("%d", &input);
	for (i = 1; sum < input;i++) {
		sum = sum + 6 * i;
	}
	output = i;
	printf("%d", output);
	return 0;
}