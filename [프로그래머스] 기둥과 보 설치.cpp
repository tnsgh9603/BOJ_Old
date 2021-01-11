#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vec;
bool column[102][102], beam[102][102];

// 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
bool check_column(int x, int y) {
	// 바닥 위에 있는 경우
	if (y == 1) {
		return true;
	}
	// 다른 기둥 위에 있는 경우
	if (column[x][y - 1]) {
		return true;
	}
	// 보의 한쪽 끝 부분 위에 있는 경우 (1)
	if (beam[x - 1][y]) {
		return true;
	}
	// 보의 한쪽 끝 부분 위에 있는 경우 (2)
	if (beam[x][y]) {
		return true;
	}
	return false;
}

// 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
bool check_beam(int x, int y) {
	// 한쪽 끝 부분이 기둥 위에 있거나 (1)
	if (column[x][y - 1]) {
		return true;
	}
	// 한쪽 끝 부분이 기둥 위에 있거나 (2)
	if (column[x + 1][y - 1]) {
		return true;
	}
	// 양쪽 끝 부분이 다른 보와 동시에 연결되어 있는 경우
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
		// (1,1)로 맞춰주기 위해 ++해줌
		x++;
		y++;

		// 기둥 설치
		if (a == 0 && b == 1) {
			if (check_column(x, y)) {
				column[x][y] = 1;
			}
		}
		// 보 설치
		else if (a == 1 && b == 1) {
			if (check_beam(x, y)) {
				beam[x][y] = 1;
			}
		}
		// 기둥 삭제
		else if (a == 0 && b == 0) {
			// 기둥 삭제
			column[x][y] = false;
			// 기둥 삭제 후, 조건을 만족하지 않으면 기둥 삭제 취소
			if (column[x][y + 1] && !check_column(x, y + 1) || (beam[x][y + 1] && !check_beam(x, y + 1)) || (beam[x - 1][y + 1] && y < n && !check_beam(x - 1, y + 1))) {
				column[x][y] = true;
			}
		}
		// 보 삭제
		else if (a == 1 && b == 0) {
			// 보 삭제
			beam[x][y] = 0;
			// 보 삭제 후, 조건을 만족하지 않으면 보 삭제 취소
			if ((column[x][y] && !check_column(x, y)) || column[x + 1][y] && !check_column(x + 1, y) || (beam[x - 1][y] && !check_beam(x - 1, y)) || (beam[x + 1][y] && !check_beam(x + 1, y))) {
				beam[x][y] = true;
			}
		}
	}

	// return 하는 배열은 x좌표 기준으로 오름차순 정렬하며, x좌표가 같을 경우 y좌표 기준으로 오름차순 정렬해주세요.
	// x, y좌표가 모두 같은 경우 기둥이 보보다 앞에 오면 됩니다.
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