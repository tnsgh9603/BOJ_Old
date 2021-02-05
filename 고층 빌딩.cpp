#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long dp[101][101][101];
int main() {
	fastio;
	int n, l, r;
	cin >> n >> l >> r;
	// 기저 사례
	// dp[N][L][R] = N개의 건물이 있을 때 왼쪽에서는 L개의 건물이 보이고 오른쪽에서는 R개의 건물이 보이는 경우의 수
	dp[1][1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			for (int k = 1; k <= r; k++) {
				dp[i][j][k] = dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
				dp[i][j][k] %= 1000000007;
			}
		}
	}
	cout << dp[n][l][r];
	return 0;
}