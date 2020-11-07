#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int array[8001] = { 0, };
	int array2[8001] = { 0, };
	int input1, input2, sum = 0, middle, max, max2 = 0, min = 0, count = 0, mode = 0, min2 = 0, count2 = 0, count3 = 0;
	cin >> input1;
	for (int i = 1; i <= input1; i++) {
		cin >> input2;
		array[input2 + 4000]++;
	}
	for (int i = 0; i <= 8000; i++) {
		if (array[i] != 0) {
			for (int k = 1; k <= array[i]; k++) {
				sum = sum + i - 4000;
				if (count != input1 / 2 + 1) {
					count++;
					middle = i - 4000;
				}
			}
		}
	}




	max = array[0];
	for (int i = 0; i <= 7999; i++) {
		if (max < array[i + 1]) {
			max = array[i + 1];
		}
	}
	for (int i = 0; i <= 8000; i++) {
		if (array[i] == max) {
			count3++;
			array2[i]++;
		}
	}
	if (count3 == 1) {
		for (int i = 0; i <= 8000; i++) {
			if (array[i] == max) {
				mode = i - 4000;
				break;
			}
		}
	}
	else {
		for (int i = 0; i <= 8000; i++) {
			if (array2[i] != 0) {
				min2 = i;
				break;
			}
		}
		for (int i = min2 + 1; i <= 8000; i++) {
			if (array2[i] != 0) {
				mode = i - 4000;
				break;
			}
		}
	}





	for (int i = 0; i <= 8000; i++) {
		if (array[i] != 0) {
			min = i - 4000;
			break;
		}
	}
	for (int i = 8000; i >= 0; i--) {
		if (array[i] != 0) {
			max2 = i - 4000;
			break;
		}
	}
	double a = sum;
	double b = input1;
	cout << round(a / b) << "\n" << middle << "\n" << mode << "\n" << max2 - min << "\n";

	return 0;
}