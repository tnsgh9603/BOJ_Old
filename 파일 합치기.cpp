#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int sum[501], dp[501][501];
int psum(int i, int j) {
	// 기저 사례
	if (i == j) {
		return 0;
	}
	// 이미 계산된 값이면 바로 리턴
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	for (int k = i; k <= j - 1; k++) {
		// ﻿dp[1][2]가 70, dp[3][4]가 80이면, dp[1][4]가 150이 아닌 dp[1][2] + dp[3][4] + [1]부터[4]까지의 합 = 300이 되어야한다.
		int temp = psum(i, k) + psum(k + 1, j) + sum[j] - sum[i - 1];
		// 최소값 갱신
		if (dp[i][j] == -1 || dp[i][j] > temp) {
			dp[i][j] = temp;
		}
	}
	return dp[i][j];
}
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int k, n;
		cin >> k;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= k; i++) {
			cin >> n;
			sum[i] = n + sum[i - 1];
		}
		cout << psum(1, k) << "\n";
	}
	return 0;
}