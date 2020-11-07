#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char input[16];
	gets(input);
	int length = strlen(input), sum = 0, number;
	for (int i = 0; i < length; i++) {
		if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C') {
			number = 3;
		}
		if (input[i] == 'D' || input[i] == 'E' || input[i] == 'F') {
			number = 4;
		}
		if (input[i] == 'G' || input[i] == 'H' || input[i] == 'I') {
			number = 5;
		}
		if (input[i] == 'J' || input[i] == 'K' || input[i] == 'L') {
			number = 6;
		}
		if (input[i] == 'M' || input[i] == 'N' || input[i] == 'O') {
			number = 7;
		}
		if (input[i] == 'P' || input[i] == 'Q' || input[i] == 'R' || input[i] == 'S') {
			number = 8;
		}
		if (input[i] == 'T' || input[i] == 'U' || input[i] == 'V') {
			number = 9;
		}
		if (input[i] == 'W' || input[i] == 'X' || input[i] == 'Y' || input[i] == 'Z') {
			number = 10;
		}
		sum = sum + number;
	}
	printf("%d", sum);
	return 0;
}