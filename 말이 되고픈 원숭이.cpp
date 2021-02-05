#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mp[201][201];
bool visited[201][201][31];
int main() {
	fastio;
	int W, H, K;
	cin >> K >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> mp[i][j];
		}
	}
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { 1, 1 }, { 0,0 } });
	visited[1][1][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int horse = q.front().second.second;
		q.pop();
		// 목적지 도달 시 종료
		if (x == H && y == W) {
			cout << cnt;
			return 0;
		}
		// 말처럼 가기
		if (horse < K) {
			for (int i = 0; i < 8; i++) {
				int dx = x + "10013443"[i] - '2';
				int dy = y + "01344310"[i] - '2';
				if (dx >= 1 && dy >= 1 && dx <= H && dy <= W) {
					if (mp[dx][dy] == 0 && !visited[dx][dy][horse + 1]) {
						visited[dx][dy][horse + 1] = 1;
						q.push({ {dx, dy}, { cnt + 1, horse + 1} });
					}
				}
			}
		}
		// 곱게 가기
		for (int i = 0; i < 4; i++) {
			int dx = x + "1120"[i] - '1';
			int dy = y + "2011"[i] - '1';
			if (dx >= 1 && dy >= 1 && dx <= H && dy <= W) {
				if (mp[dx][dy] == 0 && !visited[dx][dy][horse]) {
					visited[dx][dy][horse] = 1;
					q.push({ {dx, dy}, { cnt + 1, horse} });
				}
			}
		}
	}
	cout << -1;
	return 0;
}