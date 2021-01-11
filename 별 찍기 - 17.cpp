#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	else if (n == 2) {
		cout << " *\n";
		cout << "***\n";
		return 0;
	}
	for (int i = 1; i < n; i++) {
		for (int q = 1; q <= n - i; q++) {
			cout << " ";
		}
		cout << "*";
		if (i != 1) {
			for (int w = 1; w <= 2 * i - 3; w++) {
				cout << " ";
			}
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 1; i <= 2 * n - 1; i++) {
		cout << "*";
	}
	return 0;
}