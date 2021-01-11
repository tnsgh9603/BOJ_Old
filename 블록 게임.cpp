#include <bits/stdc++.h>
using namespace std;
//블록을 해당 위치에 떨어트릴 수 있는가?
bool can_be_located(int row, int col, vector<vector<int>>& board) {
	for (int i = 0; i < row; i++) {
		if (board[i][col] != 0) {
			return false;
		}
	}
	return true;
}
//지울수 있는 블록을 찾는다
bool check(int row, int col, int height, int width, vector<vector<int>>& board) {
	int empty_cnt = 0, type = -1;
	for (int i = row; i < row + height; i++) {
		for (int j = col; j < col + width; j++) {
			if (board[i][j] == 0) {
				// 해당 위치에 블록을 떨어뜨릴 수 없거나 빈칸이 3개 이상인 경우
				if (!can_be_located(i, j, board) || ++empty_cnt > 2) {
					return false;
				}
			}
			else {
				// 직사각형 안에 다른번호의 블록이 들어갈 경우
				if (type != -1 && type != board[i][j]) {
					return false;
				}
				type = board[i][j];
			}
		}
	}
	//영역 지우기
	for (int i = row; i < row + height; i++) {
		for (int j = col; j < col + width; j++) {
			board[i][j] = 0;
		}
	}
	return true;
}
int solution(vector<vector<int>> board) {
	int size = board.size(), ans = 0, cnt;
	while (1) {
		cnt = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				// 3 X 2 직사각형 + 범위가 안 넘어가도록 조심
				if (i <= size - 3 && j <= size - 2 && check(i, j, 3, 2, board)) {
					cnt++;
				}
				// 2 X 3 직사각형
				else if (i <= size - 2 && j <= size - 3 && check(i, j, 2, 3, board)) {
					cnt++;
				}
			}
		}
		ans += cnt;
		if (!cnt) {
			break;
		}
	}
	return ans;
}