#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, d, e, f, ans = 0;
	cin >> a >> b >> c >> d >> e >> f;
	if (d > a) {
		ans += d - a;
	}
	if (e > b) {
		ans += e - b;
	}
	if (f > c) {
		ans += f - c;
	}
	cout << ans;
	return 0;
}