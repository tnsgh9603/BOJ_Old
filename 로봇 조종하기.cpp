#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, m, INF = 1000000, mp[1001][1001], arr[1001][1001][3];
bool visited[1001][1001];
int dfs(int y, int x, int dir) {
	//기저사례
	if (y == n - 1 && x == m - 1) {
		return mp[y][x];
	}
	int& res = arr[y][x][dir];
	if (res != -INF) {
		return res;
	}
	// 위로는 이동 안됨
	for (int i = 0; i < 3; i++) {
		int ty = y + "211"[i] - '1';
		int tx = x + "120"[i] - '1';
		// 범위 벗어나는 거는 무시
		if (ty < 0 || ty >= n || tx < 0 || tx >= m || visited[ty][tx]) {
			continue;
		}
		visited[ty][tx] = true;
		res = max(res, dfs(ty, tx, i) + mp[y][x]);
		visited[ty][tx] = false;
	}
	return res;
}
int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mp[i][j];
			arr[i][j][0] = arr[i][j][1] = arr[i][j][2] = -INF;
		}
	}
	visited[0][0] = true;
	cout << dfs(0, 0, 0) << '\n';
	return 0;
}
/*
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mp[1001][1002], dp[1001][1002], arr[2][1002];
int main() {
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> mp[i][j];
		}
	}
	// 첫 줄은 오른쪽으로만 이동 가능
	for (int j = 1; j <= M; j++) {
		dp[1][j] += dp[1][j - 1] + mp[1][j];
	}
	// 둘째 줄 부터 따로 처리
	for (int i = 2; i <= N; i++) {
		// 기저 사례
		arr[0][0] = dp[i - 1][1];
		for (int j = 1; j <= M; j++) {
			// 위에서 바로 내려오는 경우의 값이 큰지, 왼쪽에서 오른쪽으로 가는 경우의 값이 큰지 비교
			arr[0][j] = max(dp[i - 1][j], arr[0][j - 1]) + mp[i][j];
		}
		// 기저 사례
		arr[1][M + 1] = dp[i - 1][M];
		for (int j = M; j > 0; j--) {
			// 위에서 바로 내려오는 경우의 값이 큰지, 오른쪽에서 왼쪽으로 가는 경우의 값이 큰지 비교
			arr[1][j] = max(dp[i - 1][j], arr[1][j + 1]) + mp[i][j];
		}
		for (int j = 1; j <= M; j++) {
			// 두 경우의 수 중 최대값 저장
			dp[i][j] = max(arr[0][j], arr[1][j]);
		}
	}
	cout << dp[N][M];
	return 0;
}
*/