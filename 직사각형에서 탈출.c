#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	double x, y, w, h, difference1, difference2;
	scanf("%lf %lf %lf %lf", &x, &y, &w, &h);
	if (x >= w / 2) {
		difference1 = w - x;
	}
	else {
		difference1 = x;
	}
	if (y >= h / 2) {
		difference2 = h - y;
	}
	else {
		difference2 = y;
	}
	if (difference1 >= difference2) {
		printf("%.0f", difference2);
	}
	else {
		printf("%.0f", difference1);
	}
	return 0;
}