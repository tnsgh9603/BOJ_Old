#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int prev;
		cin >> prev;
		int ans = 0;
		while (1) {
			int cur;
			cin >> cur;
			if (!cur) {
				break;
			}
			if (cur > 2 * prev) {
				ans += cur - 2 * prev;
			}
			prev = cur;
		}
		cout << ans << "\n";
	}
	return 0;
}