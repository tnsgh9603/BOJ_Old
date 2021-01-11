#include <bits/stdc++.h>
using namespace std;
//����� �ش� ��ġ�� ����Ʈ�� �� �ִ°�?
bool can_be_located(int row, int col, vector<vector<int>>& board) {
	for (int i = 0; i < row; i++) {
		if (board[i][col] != 0) {
			return false;
		}
	}
	return true;
}
//����� �ִ� ����� ã�´�
bool check(int row, int col, int height, int width, vector<vector<int>>& board) {
	int empty_cnt = 0, type = -1;
	for (int i = row; i < row + height; i++) {
		for (int j = col; j < col + width; j++) {
			if (board[i][j] == 0) {
				// �ش� ��ġ�� ����� ����߸� �� ���ų� ��ĭ�� 3�� �̻��� ���
				if (!can_be_located(i, j, board) || ++empty_cnt > 2) {
					return false;
				}
			}
			else {
				// ���簢�� �ȿ� �ٸ���ȣ�� ����� �� ���
				if (type != -1 && type != board[i][j]) {
					return false;
				}
				type = board[i][j];
			}
		}
	}
	//���� �����
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
				// 3 X 2 ���簢�� + ������ �� �Ѿ���� ����
				if (i <= size - 3 && j <= size - 2 && check(i, j, 3, 2, board)) {
					cnt++;
				}
				// 2 X 3 ���簢��
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