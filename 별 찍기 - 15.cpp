#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n - i; k++) {
			cout << " ";
		}
		cout << "*";
		for (int q = 1; q <= (i - 1) * 2 - 1; q++) {
			cout << " ";
		}
		if (i != 1) {
			cout << "*";
		}
		cout << "\n";
	}
	return 0;
}	