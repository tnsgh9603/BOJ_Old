#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number, W, H, N, front, back;
	scanf("%d", &number);
	for(int i = 1; i <= number; i++) {
		scanf("%d %d %d", &H, &W, &N);
		if (N % H == 0) {
			front = H;
			back = N / H;
		}
		else {
			front = N % H;
			back = (N / H) + 1;
		}
		if (back < 10) {
			printf("%d%d%d\n", front, 0, back);
		}
		else {
			printf("%d%d\n", front, back);
		}
	}
	return 0;
}