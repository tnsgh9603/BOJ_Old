#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[501][2];
int dp[501][501];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i < n; i++) {
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= n; m++) { 
		for (int i = 1; i <= n - m; i++) { 
			int j = i + m;
			for (int k = i; k < j; k++) {
				// 갱신
				int res = dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1];
				// 아래 if문(!dp[i][j])으로 처음 dp를 초기화 할때, 즉 처음에는 dp가 0일때는 초기값으로 넣어준다.
				// 그리고 dp가 갱신되고 난 다음에는 dp[i][j]가 res보다 클때만 갱신해준다.
				if (!dp[i][j] || dp[i][j] > res) {
					dp[i][j] = res;
				}
			}
		}
	}
	cout << dp[1][n];
}