#include <iostream>
using namespace std;
int main() {
	int a, max, order = 1;
	for (int i = 1; i <= 9; i++) {
		cin >> a;
		if (i == 1) {
			max = a;
		}
		if (max < a) {
			max = a;
			order = i;
		}
	}
	cout << max << endl << order;
	return 0;
}