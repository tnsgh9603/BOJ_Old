#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void solve() {
	int n, m;
	cin >> n >> m;
	if (n < 12) {
		cout << -1 << "\n";
		return;
	}
	if (m < 4) {
		cout << -1 << "\n";
		return;
	}
	cout << 11 * m + 4 << "\n";
}
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}