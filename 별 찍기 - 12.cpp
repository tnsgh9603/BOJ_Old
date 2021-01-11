#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int q = 1; q <= n - 1; q++) {
		for (int w = n - q; w >= 1; w--) {
			cout << " ";
		}
		for (int e = 1; e <= q; e++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int q = 1; q <= n; q++) {
		cout << "*";
	}
	cout << "\n";
	for (int q = 1; q <= n - 1; q++) {
		for (int e = 1; e <= q; e++) {
			cout << " ";
		}
		for (int w = n - q; w >= 1; w--) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}