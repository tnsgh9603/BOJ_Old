#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int A, B, N, M, mp[101][101], robot[101][3];
bool crash;
bool simulation(int idx, char cmd, int cnt) {
	int dx = robot[idx][0], dy = robot[idx][1], dir = robot[idx][2];
	// ���� �κ��� ��Ҹ� 0���� �ʱ�ȭ
	mp[dx][dy] = 0;
	// ��� Ƚ����ŭ ����
	while (cnt--) {
		// ���� ��ȯ
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
		// ������ �̵�
		else {
			// ���� ���⿡ �°� �̵�
			dx += "0121"[dir] - '1';
			dy += "1210"[dir] - '1';

			//���� �浹�� ���
			if (dx <= 0 || dy <= 0 || dx > A || dy > B) {
				cout << "Robot " << idx << " crashes into the wall" << "\n";
				return 1;
			}

			//�ٸ� �κ��� �浹�� ���
			if (mp[dx][dy] != 0) {
				cout << "Robot " << idx << " crashes into robot " << mp[dx][dy] << "\n";
				return 1;
			}
		}
	}
	//�浹�� �߻����� �ʾ��� ���, �κ���ġ ����
	mp[dx][dy] = idx;
	robot[idx][0] = dx;
	robot[idx][1] = dy;
	robot[idx][2] = dir;
	return false;
}

int main() {

	fastio;
	cin >> B >> A >> N >> M;
	// �κ��� ��ġ�� �Է¹޾� ����
	for (int i = 1; i <= N; ++i) {
		int x, y, dir;
		char tmp;
		cin >> y >> x >> tmp;
		// ���� ����
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
		// ���� ��ġ�� x,y ��ǥ, ����, �κ���ȣ ����
		robot[i][0] = (A + 1) - x;
		robot[i][1] = y;
		robot[i][2] = dir;
		mp[robot[i][0]][robot[i][1]] = i;
	}

	// ��ɾ� ����
	for (int i = 1; i <= M; i++) {
		int idx, cnt;
		char cmd;
		cin >> idx >> cmd >> cnt;
		// ��ɾ� ����
		crash = simulation(idx, cmd, cnt);
		// �浹 �߻� �� ����
		if (crash) {
			return 0;
		}
	}
	// �߸��� ����� ���� ��
	if (!crash) {
		cout << "OK" << "\n";
	}
	return 0;
}