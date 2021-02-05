#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vector<int>v;
		while (c != 0) {
			v.push_back(c % b);
			c /= b;
		}
		int ans = 0;
		for (auto x : v) {
			ans += x * x;
		}
		cout << i + 1 << " " << ans << '\n';
	}
	return 0;
}