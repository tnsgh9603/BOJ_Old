#include <iostream>
using namespace std;
int main() {
	int x, k;
	cin >> x >> k;
	if (7000 * k <= x * 1000) {
		cout << 7000 * k;
	}
	else if (3500 * k <= x * 1000) {
		cout << 3500 * k;
	}
	else if (1750 * k <= x * 1000) {
		cout << 1750 * k;
	}
	else {
		cout << 0;
	}
	return 0;
}