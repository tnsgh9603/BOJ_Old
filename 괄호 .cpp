#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define MOD 1000000007;
long long dp[5001];
int main() {
	fastio;
	// ±âÀú »ç·Ê
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= 5000; i += 2) {
		for (int j = 0; j <= i - 2; j += 2) {
			dp[i] += dp[j] * dp[i - j - 2];
			dp[i] %= MOD;
		}
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
	return 0;
}