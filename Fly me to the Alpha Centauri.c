#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	long long number, start, end, a = 0, count = 0;
	scanf("%lld", &number);
	for (int i = 1; i <= number; i++) {
		scanf("%lld %lld", &start, &end);
		if (end - start == 0) {
			count = 1;
		}
		else {
			for (int i = 1; a < end - start; i++) {
				a = a + i;
				count++;
				if (a >= end - start) {
					break;
				}
				a = a + i;
				count++;
			}
		}
		printf("%lld\n", count);
		a = 0, count = 0;
	}
	return 0;
}