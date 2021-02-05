#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t, n, ans;
	cin >> t;
	while (t--) {
		cin >> n;
		ans = n;
		while (n != 1) {
			if (n % 2) {
				n = 3 * n + 1;
				ans = max(ans, n);
			}
			else {
				n /= 2;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}