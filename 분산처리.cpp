#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (a % 10 == 0) {
			cout << 10 << "\n";
			continue;
		}
		c = 1;
		a %= 10;
		b = (b - 1) % 4 + 1;
		while (b--) {
			c *= a;
		}
		cout << c % 10 << "\n";
	}
	return 0;
}
