#include <iostream>
#include <cmath>
using namespace std;
// log 2 (500000) -> 18.xxxx 이므로 배열의 크기를 [19]로 설정
long long dp[500001][19];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, Q, n, x;
	cin >> m;
	// dp[i][n] -> f_i(n) -> n에서 i번 이동 후의 값 저장
	for (int i = 1; i <= m; i++) {
		cin >> dp[i][0];
	}
	for (int j = 1; j < log2(500000); j++) {
		for (int i = 1; i <= m; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	cin >> Q;
	while (Q--) {
		cin >> n >> x;
		for (int i = 0; n; i++) {
			if (n & 1) {
				x = dp[x][i];
			}
			n >>= 1;
		}
		cout << x << "\n";
	}
}
/*
#include <iostream>
#include <vector>
using namespace std;
int arr[200001];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int m, input, Q, n, x, answer;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> arr[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> n >> x;
		for (int i = 1; i <= n; i++) {
			x = arr[x];
		}
		cout << x << "\n";
	}
	return 0;
}
*/