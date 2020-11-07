#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	double number, x1, y1, r1, x2, y2, r2, distance, short_radius, long_radius;
	scanf("%lf", &number);
	for (int i = 1; i <= number; i++) {
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
		if (r1 >= r2) {
			long_radius = r1;
			short_radius = r2;
		}
		else {
			long_radius = r2;
			short_radius = r1;
		}
		distance = sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1));
		if (x1 == x2 && y1 == y2 && r1 == r2) {
			printf("-1\n");
		}
		else if (distance > r1 + r2) {
			printf("0\n");
		}
		else if (distance == r1 + r2) {
			printf("1\n");
		}
		else {
			if (distance + short_radius > long_radius) {
				printf("2\n");
			}
			else if (distance + short_radius == long_radius) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
	}
	return 0;
}