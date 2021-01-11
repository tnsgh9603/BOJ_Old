#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[201][201];
long long sum[201][201];
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			// sum[a][b] -> (1,1)부터 (a,b)까지의 총합
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + arr[i][j];
		}
	}
	long long ans = -INT_MAX;
	for (int x = 1; x <= n; x++) {
		// y가 여기서 m이 되어야 하는데 n으로 해도 맞다... 테케가 부족한듯 
		for (int y = 1; y <= n; y++) {
			for (int a = x; a <= n; a++) {
				for (int b = y; b <= m; b++) {
					// 최대값 갱신
					ans = max(ans, sum[a][b] - sum[x - 1][b] - sum[a][y - 1] + sum[x - 1][y - 1]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}