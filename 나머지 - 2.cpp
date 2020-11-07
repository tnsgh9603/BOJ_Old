#include <iostream>
using namespace std;
int main() {
	int array[43] = { 0, }, input, order, count = 0;
	for (int i = 1; i <= 10; i++) {
		cin >> input;
		order = input % 42;
		array[order]++;
	}
	for (int k = 0; k <= 42; k++) {
		if (array[k] != 0) {
			count++;
		}
	}
	cout << count;
	return 0;
}