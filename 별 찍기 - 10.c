#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int array[2187][2187] = { 0, };
int star(int a,int input) {
	if(a >= 3) {
		for (int q = 1; a * q / 3 <= input; q = q + 3) {
			for (int x = (a * q / 3); x <= (a * (q + 1) / 3) - 1; x++) {
				for (int z = 1; a * z / 3 <= input; z = z + 3) {
					for (int w = (a * z / 3); w <= (a * (z + 1) / 3) - 1; w++) {
						array[x][w]++;
					}
				}
			}
		}
		star(a / 3,input);
	}
}
int main() {
	int input;
	scanf("%d", &input);
	star(input, input);
	for (int i = 0; i <= input - 1; i++) {
		for (int k = 0; k <= input - 1; k++) {
			if (array[i][k] == 0) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}