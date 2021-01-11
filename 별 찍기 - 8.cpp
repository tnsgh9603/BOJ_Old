#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int q = 1; q <= n - 1; q++) {
		for (int w = 1; w <= q; w++) {
			cout << "*";
		}
		for (int e = 1; e <= 2 * (n - q); e++) {
			cout << " ";
		}
		for (int w = 1; w <= q; w++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int q = 1; q <= 2 * n; q++) {
		cout << "*";
	}
	cout << "\n";
	for (int q = n - 1; q >= 1; q--) {
		for (int w = 1; w <= q; w++) {
			cout << "*";
		}
		for (int e = 1; e <= 2 * (n - q); e++) {
			cout << " ";
		}
		for (int w = 1; w <= q; w++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}