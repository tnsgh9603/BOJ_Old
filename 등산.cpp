#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;

int N, M, T, D;
int res;
int p[26][26]; // ���� ����
int visit[26][26]; // ��� �ð�
int back[26][26]; // �ϻ� �ð�
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
			if (nx<1 || ny<1 || nx>N || ny>M) { // �迭 ���� ����� ��� ���� 
				continue;
			}
			if (abs(p[nx][ny] - p[x][y]) > T) { // �������� T���� ū ��� ����
				continue;
			} 
			if (p[nx][ny] <= p[x][y]) { // ���̰� ���� ���� ���ų� �������� ���
				if (visit[x][y] >= D) { // D�ð� �ʰ��ϴ� ��� ����
					continue;
				} 
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + 1) { 
					// visit[nx][ny]�� �湮���� �ʾҰų� �� ���� ��찡 �����ϸ� ������Ʈ
					visit[nx][ny] = visit[x][y] + 1; // ���̰� ���� ���� ���ų� ������ �� �ɸ��� �ð��� 1��
					q.push({ nx,ny });
				}
			}
			else { // �ö󰡴� ���
				int nextTime = (p[nx][ny] - p[x][y]) * (p[nx][ny] - p[x][y]);
				if (visit[x][y] + nextTime > D) { // D�ð� �ʰ��ϴ� ��� ����
					continue;
				}
				if (visit[nx][ny] == -1 || visit[nx][ny] > visit[x][y] + nextTime) {
					// visit[nx][ny]�� �湮���� �ʾҰų� �� ���� ��찡 �����ϸ� ������Ʈ
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
			if (nx<1 || ny<1 || nx>N || ny>M) { // �迭 ���� ����� ��� ���� 
				continue;
			}
			if (abs(p[nx][ny] - p[x][y]) > T) { // �������� T���� ū ��� ����
				continue;
			}
			if (p[x][y] > p[nx][ny]) { // ���̰� ���� ���� ���ų� �������� ���
				int nextTime = (p[x][y] - p[nx][ny]) * (p[x][y] - p[nx][ny]);
				if (back[x][y] + nextTime > D) continue; // D�ð� �ʰ��ϴ� ��� ����
				if (back[nx][ny] == -1 || back[nx][ny] > back[x][y] + nextTime) {
					// visit[nx][ny]�� �湮���� �ʾҰų� �� ���� ��찡 �����ϸ� ������Ʈ
					back[nx][ny] = back[x][y] + nextTime;
					q.push({ nx,ny });
				}
			}
			else { // �������� ���
				if (back[x][y] + 1 > D) { // D�ð� �ʰ��ϴ� ��� ����
					continue;
				} 
				if (back[nx][ny] == -1 || back[nx][ny] > back[x][y] + 1) {
					// visit[nx][ny]�� �湮���� �ʾҰų� �� ���� ��찡 �����ϸ� ������Ʈ
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
			// ���ڿ��� ���̷� �ٲٴ� ����
			if ('A' <= input && input <= 'Z') p[i][j] = (input - 'A');
			else p[i][j] = (input - 'a' + 26);
		}
	}

	bfs(); // ȣ�� -> ��
	bfs2(); // �� -> ȣ��

	res = p[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visit[i][j] == -1 || back[i][j] == -1) { // �湮�� �� ���� ���� ����
				continue; 
			}
			if (visit[i][j] + back[i][j] <= D) { // �ð� �ȿ� ���ٿ��� ��쿡 ���� ���
				res = max(res, p[i][j]); // ȣ���� ���̰� ���� ���� ��쵵 �����Ƿ� max�Լ� �̿�
			}
		}
	}
	cout << res;
}