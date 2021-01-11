#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int k = n;
	for (int i = 1; i <= 2*n; i++) {
		for (int q = 1; q <= n; q++) {
			cout << "* ";
		}
		if (!--k) {
			break;
		}
		cout << "\n";
		for (int w = 1; w <= n; w++) {
			cout << " *";
		}
		if (!--k) {
			break;
		}
		cout << "\n";
	}
	return 0;
}