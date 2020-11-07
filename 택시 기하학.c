#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main() {
	double input;
	scanf("%lf", &input);
	printf("%f\n", input * input * 3.14159265358979323846264338327950288);
	printf("%f\n", input * input * 2);
	return 0;
}