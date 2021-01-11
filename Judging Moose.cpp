#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "Not a moose";
	}
	else if (a == b) {
		cout << "Even " << 2 * a;
	}
	else {
		cout << "Odd " << 2 * max(a, b);
	}
	return 0;
}