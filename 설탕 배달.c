#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, count1 = 0, count2 = 0;
	scanf("%d", &number);
	if (number == 4 || number == 7) {
		printf("-1");
	}
	else if (number == 6 || number == 9 || number == 12) {
		printf("%d", number / 3);
	}
	else {
		if (number % 5 == 0) {
			count1 = number / 5;
		}
		else {
			for (; number-5 > 0; number = number - 5) {
				count1++;
			}
			for (; number % 3 != 0; ) {
				count1--;
				count2++;
				number = number + 5;
			}
			if (number %3==0) {
				count2 = number / 3;
			}
		}
		printf("%d", count1 + count2);
	}
	return 0;
}