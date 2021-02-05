#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int MOD = 1e9 + 7;
int main() {
	fastio;
	int H, x, f, ans = 0, c;
	cin >> H >> x;
	f = x;
	while (H--) {
		cin >> c;
		ans = (ans + (long long)c * f % MOD) % MOD;
		f = ((long long)f * x) % MOD;
	}
	cout << ans;
	return 0;
}