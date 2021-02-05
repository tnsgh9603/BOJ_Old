#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool f(int a, int b, int c, int d) {
	if (b + b == a + c && c + c == b + d) {
		return 1;
	}
	if (b * b == a * c && c * c == b * d) {
		return 1;
	}
	return 0;
}
int main() {
	fastio;
	int i, a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (a == -1 && b == -1) {
			break;
		}
		for (i = 1; i <= 10000; i++) {
			if (a == -1) {
				a = i;
				if (f(a, b, c, d)) {
					break;
				}
				a = -1;
			}
			if (b == -1) {
				b = i;
				if (f(a, b, c, d)) {
					break;
				}
				b = -1;
			}
			if (c == -1) {
				c = i;
				if (f(a, b, c, d)) {
					break;
				}
				c = -1;
			}
			if (d == -1) {
				d = i;
				if (f(a, b, c, d)) {
					break;
				}
				d = -1;
			}
		}
		if (i > 10000) {
			cout << "-1\n";
		}
		else {
			cout << i << "\n";
		}
	}
	return 0;
}