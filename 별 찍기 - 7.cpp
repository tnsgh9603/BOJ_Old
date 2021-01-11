#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	int k = 0;
	for (int q = 1; q <= n; q++) {
		for (int i = n - q - 1; i >= 0; i--) {
			cout << " ";
		}
		for (int i = 1; i <= 2 * (q - 1) + 1; i++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int q = 2; q <= n; q++) {
		for (int i = 1; i <= q - 1; i++) {
			cout << " ";
		}
		for (int i = 1; i <= (2 * n) - 1 - 2 * (q - 1); i++) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}