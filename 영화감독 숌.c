#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int input, array[20000], count = 0, copy, order = 1;
	scanf("%d", &input);
	for (int i = 666; i <= 3000000; i++) {
		copy = i;
		while (i > 0) {
			if (i % 10 == 6) {
				count++;
				if (count == 3) {
					array[order] = copy;
					order++;
					break;
				}
			}
			else {
				count = 0;
			}
			i = i / 10;
		}
		count = 0;
		i = copy;
	}
	printf("%d", array[input]);
	return 0;
}