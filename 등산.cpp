#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int N, M, T, D;
int res;
int p[26][26]; // 지도 정보
int visit[26][26]; // 등산 시간
int back[26][26]; // 하산 시간
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void bfs()
{
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	visit[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) { // 배열 밖을 벗어나는 경우 무시 
				continue;
			}
			if (abs(p[nx][ny] - p[x][y]) > T) { // 높이차가 T보다 큰 경우 무시
				continue;
			} 
			if (p[nx][ny] <= p[x][y]) { // 높이가 같은 곳을 가거나 내려가는 경우
				if (visit[x][y] >= D) { // D시간 초과하는 경우 무시
					continue;
				} 
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + 1) { 
					// visit[nx][ny]에 방문하지 않았거나 더 빠른 경우가 존재하면 업데이트
					visit[nx][ny] = visit[x][y] + 1; // 높이가 같은 곳을 가거나 내려갈 때 걸리는 시간은 1초
					q.push({ nx,ny });
				}
			}
			else { // 올라가는 경우
				int nextTime = (p[nx][ny] - p[x][y]) * (p[nx][ny] - p[x][y]);
				if (visit[x][y] + nextTime > D) { // D시간 초과하는 경우 무시
					continue;
				}
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + nextTime) {
					// visit[nx][ny]에 방문하지 않았거나 더 빠른 경우가 존재하면 업데이트
					visit[nx][ny] = visit[x][y] + nextTime;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void bfs2()
{
	memset(back, -1, sizeof(back));
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	back[1][1] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>N || ny>M) { // 배열 밖을 벗어나는 경우 무시 
				continue;
			}
			if (abs(p[nx][ny] - p[x][y]) > T) { // 높이차가 T보다 큰 경우 무시
				continue;
			}
			if (p[x][y] > p[nx][ny]) { // 높이가 같은 곳을 가거나 내려가는 경우
				int nextTime = (p[x][y] - p[nx][ny]) * (p[x][y] - p[nx][ny]);
				if (back[x][y] + nextTime > D) continue; // D시간 초과하는 경우 무시
				if (back[nx][ny] == -1 || back[nx][ny] > back[x][y] + nextTime) {
					// visit[nx][ny]에 방문하지 않았거나 더 빠른 경우가 존재하면 업데이트
					back[nx][ny] = back[x][y] + nextTime;
					q.push({ nx,ny });
				}
			}
			else { // 내려가는 경우
				if (back[x][y] + 1 > D) { // D시간 초과하는 경우 무시
					continue;
				} 
				if (back[nx][ny] == -1 || back[nx][ny] > back[x][y] + 1) {
					// visit[nx][ny]에 방문하지 않았거나 더 빠른 경우가 존재하면 업데이트
					back[nx][ny] = back[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}
int main()
{
	char input;
	cin >> N >> M >> T >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input; 
			// 문자열을 높이로 바꾸는 과정
			if ('A' <= input && input <= 'Z') p[i][j] = (input - 'A');
			else p[i][j] = (input - 'a' + 26);
		}
	}

	bfs(); // 호텔 -> 산
	bfs2(); // 산 -> 호텔

	res = p[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j] == -1 || back[i][j] == -1) { // 방문할 수 없는 곳은 제외
				continue; 
			}
			if (visit[i][j] + back[i][j] <= D) { // 시간 안에 갔다오는 경우에 한해 출력
				res = max(res, p[i][j]); // 호텔이 높이가 제일 높을 경우도 있으므로 max함수 이용
			}
		}
	}
	cout << res;
}