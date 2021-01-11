#include <iostream>
using namespace std;
int main() {
	int a, ans;
	cin >> a;
	if (a % 8 == 0) {
		ans = 2;
	}
	if (a % 8 == 1) {
		ans = 1;
	}
	if (a % 8 == 2) {
		ans = 2;
	}
	if (a % 8 == 3) {
		ans = 3;
	}
	if (a % 8 == 4) {
		ans = 4;
	}
	if (a % 8 == 5) {
		ans = 5;
	}
	if (a % 8 == 6) {
		ans = 4;
	}
	if (a % 8 == 7) {
		ans = 3;
	}
	cout << ans;
}