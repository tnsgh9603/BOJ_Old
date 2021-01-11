#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
bool visited[1001][1001];
queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	bool traverse;
	int m, n, i, j, k, seg = 0, cnt = 0, ans = 0;

	cin >> m >> n;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				seg++;
			}
		}
	}

	while (!q.empty()) {
		cnt = 0;
		traverse = false;
		for (i = 0; i < seg; i++) {

			pair<int, int> newc = q.front();
			q.pop();

			visited[newc.first][newc.second] = true;

			for (k = 0; k < 4; k++) {
				int newy = newc.first + "1210"[k] - '1';
				int newx = newc.second + "2101"[k] - '1';

				if (newx > 0 && newx <= m && newy > 0 && newy <= n && !visited[newy][newx] && arr[newy][newx] == 0) {
					traverse = true;
					arr[newy][newx] = 1;
					q.push(make_pair(newy, newx));
					cnt++;
				}
			}
		}
		seg = cnt;
		if (traverse) {
			ans++;
		}
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}