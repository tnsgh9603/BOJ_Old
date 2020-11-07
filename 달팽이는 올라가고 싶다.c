#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int up, down, height, time;
	scanf("%d %d %d", &up, &down, &height);
	if ((height - up) % (up - down)==0) {
		time = ((height - up) / (up - down)) + 1;
	}
	else {
		time = ((height - up) / (up - down)) + 2;
	}
	printf("%d", time);
	return 0;
}