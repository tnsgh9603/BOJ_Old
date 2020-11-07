#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int test_number, student_number, test_score, sum = 0, count = 0;
	scanf("%d\n", &test_number);
	for (int i = 1; i <= test_number; i++) {
		int test_score_array[1000] = { 0, };
		scanf("%d", &student_number);
		for (int i = 0; i < student_number; i++) {
			scanf("%d", &test_score);
			test_score_array[i] = test_score;
			sum = sum + test_score;
			
		}
		for (int i = 0; i < student_number; i++) {
			double average = sum / student_number;
			if (test_score_array[i] > average) {
				count++;
			}
		}
		double ratio = (double)count / (double)student_number ;
		printf("%.3f",ratio*100);
		printf("%%\n");
		count = 0;
		sum = 0;
	}
	return 0;
}