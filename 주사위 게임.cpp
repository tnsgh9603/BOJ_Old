#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, t, ans = 0;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		if (a == b && b == c) {
			ans = max(ans, 10000 + a * 1000);
		}
		else if (a == b) {
			ans = max(ans, 1000 + a * 100);
		}
		else if (b == c) {
			ans = max(ans, 1000 + b * 100);
		}
		else if (a == c) {
			ans = max(ans, 1000 + c * 100);
		}
		else {
			ans = max(ans, max(a,(max(b,c))) * 100);
		}
	}
	cout << ans;
	return 0;
}