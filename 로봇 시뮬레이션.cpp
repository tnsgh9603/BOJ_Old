#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int A, B, N, M, mp[101][101], robot[101][3];
bool crash;
bool simulation(int idx, char cmd, int cnt) {
	int dx = robot[idx][0], dy = robot[idx][1], dir = robot[idx][2];
	// 현재 로봇의 장소를 0으로 초기화
	mp[dx][dy] = 0;
	// 명령 횟수만큼 실행
	while (cnt--) {
		// 방향 전환
		if (cmd == 'L') {
			if (dir == 0) {
				dir = 3;
			}
			else {
				dir--;
			}
		}
		else if (cmd == 'R') {
			if (dir == 3) {
				dir = 0;
			}
			else {
				dir++;
			}
		}
		// 앞으로 이동
		else {
			// 현재 방향에 맞게 이동
			dx += "0121"[dir] - '1';
			dy += "1210"[dir] - '1';

			//벽에 충돌한 경우
			if (dx <= 0 || dy <= 0 || dx > A || dy > B) {
				cout << "Robot " << idx << " crashes into the wall" << "\n";
				return 1;
			}

			//다른 로봇에 충돌한 경우
			if (mp[dx][dy] != 0) {
				cout << "Robot " << idx << " crashes into robot " << mp[dx][dy] << "\n";
				return 1;
			}
		}
	}
	//충돌이 발생하지 않았을 경우, 로봇위치 변경
	mp[dx][dy] = idx;
	robot[idx][0] = dx;
	robot[idx][1] = dy;
	robot[idx][2] = dir;
	return false;
}

int main() {

	fastio;
	cin >> B >> A >> N >> M;
	// 로봇의 위치를 입력받아 저장
	for (int i = 1; i <= N; ++i) {
		int x, y, dir;
		char tmp;
		cin >> y >> x >> tmp;
		// 방향 저장
		if (tmp == 'N') {
			dir = 0;
		}
		else if (tmp == 'E') {
			dir = 1;
		}
		else if (tmp == 'S') {
			dir = 2;
		}
		else {
			dir = 3;
		}
		// 현재 위치한 x,y 좌표, 방향, 로봇번호 저장
		robot[i][0] = (A + 1) - x;
		robot[i][1] = y;
		robot[i][2] = dir;
		mp[robot[i][0]][robot[i][1]] = i;
	}

	// 명령어 수행
	for (int i = 1; i <= M; i++) {
		int idx, cnt;
		char cmd;
		cin >> idx >> cmd >> cnt;
		// 명령어 실행
		crash = simulation(idx, cmd, cnt);
		// 충돌 발생 시 종료
		if (crash) {
			return 0;
		}
	}
	// 잘못된 명령이 없을 시
	if (!crash) {
		cout << "OK" << "\n";
	}
	return 0;
}