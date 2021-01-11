#include <iostream>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	int k = 0;
	for (int q = 1; q <= n; q++) {
		for (int i = 1; i <= k; i++) {
			cout << " ";
		}
		for (int i = n; i > k; i--) {
			cout << "*";
		}
		k++;
		cout << "\n";
	}
	return 0;
}