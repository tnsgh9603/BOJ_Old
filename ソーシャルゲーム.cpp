#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, ans;
	cin >> a >> b >> c;
	ans = c / (7 * a + b) * 7;
	c %= (7 * a + b);
	if (c % a == 0) {
		ans += min(c / a, 7);
	}
	else {
		ans += min(c / a + 1, 7);
	}
	cout << ans;
	return 0;
}