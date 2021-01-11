#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vec;
bool column[102][102], beam[102][102];

// ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
bool check_column(int x, int y) {
	// �ٴ� ���� �ִ� ���
	if (y == 1) {
		return true;
	}
	// �ٸ� ��� ���� �ִ� ���
	if (column[x][y - 1]) {
		return true;
	}
	// ���� ���� �� �κ� ���� �ִ� ��� (1)
	if (beam[x - 1][y]) {
		return true;
	}
	// ���� ���� �� �κ� ���� �ִ� ��� (2)
	if (beam[x][y]) {
		return true;
	}
	return false;
}

// ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
bool check_beam(int x, int y) {
	// ���� �� �κ��� ��� ���� �ְų� (1)
	if (column[x][y - 1]) {
		return true;
	}
	// ���� �� �κ��� ��� ���� �ְų� (2)
	if (column[x + 1][y - 1]) {
		return true;
	}
	// ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �ִ� ���
	if (beam[x + 1][y] && beam[x - 1][y]) {
		return true;
	}
	return false;
}

vec solution(int n, vec input) {
	vec answer;
	for (int i = 0; i < input.size(); i++) {
		int x, y, a, b;
		x = input[i][0];
		y = input[i][1];
		a = input[i][2];
		b = input[i][3];
		// (1,1)�� �����ֱ� ���� ++����
		x++;
		y++;

		// ��� ��ġ
		if (a == 0 && b == 1) {
			if (check_column(x, y)) {
				column[x][y] = 1;
			}
		}
		// �� ��ġ
		else if (a == 1 && b == 1) {
			if (check_beam(x, y)) {
				beam[x][y] = 1;
			}
		}
		// ��� ����
		else if (a == 0 && b == 0) {
			// ��� ����
			column[x][y] = false;
			// ��� ���� ��, ������ �������� ������ ��� ���� ���
			if (column[x][y + 1] && !check_column(x, y + 1) || (beam[x][y + 1] && !check_beam(x, y + 1)) || (beam[x - 1][y + 1] && y < n && !check_beam(x - 1, y + 1))) {
				column[x][y] = true;
			}
		}
		// �� ����
		else if (a == 1 && b == 0) {
			// �� ����
			beam[x][y] = 0;
			// �� ���� ��, ������ �������� ������ �� ���� ���
			if ((column[x][y] && !check_column(x, y)) || column[x + 1][y] && !check_column(x + 1, y) || (beam[x - 1][y] && !check_beam(x - 1, y)) || (beam[x + 1][y] && !check_beam(x + 1, y))) {
				beam[x][y] = true;
			}
		}
	}

	// return �ϴ� �迭�� x��ǥ �������� �������� �����ϸ�, x��ǥ�� ���� ��� y��ǥ �������� �������� �������ּ���.
	// x, y��ǥ�� ��� ���� ��� ����� ������ �տ� ���� �˴ϴ�.
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (column[i][j]) {
				answer.push_back({ i - 1, j - 1, 0 });
			}
			if (beam[i][j]) {
				answer.push_back({ i - 1, j - 1, 1 });
			}
		}
	}

	return answer;
}