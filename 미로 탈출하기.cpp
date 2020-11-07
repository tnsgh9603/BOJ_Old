#include <iostream>
using namespace std;
char arr[501][501];
int visited[501][501];		//-1: �湮 x, 0: ��������, 1: ������
int row, col, result = 0;

int dfs(int x, int y) {
	if (visited[x][y] != -1) {
		return visited[x][y];		// �����ų� ������ ���ϴ� ���
	}
	char c = arr[x][y];
	int temp = 0;
	visited[x][y] = 0;
	if (c == 'U') { // U -> ����, R -> ������, D -> �Ʒ���, L-> ����
		if (x == 0) { 
			temp = 1;
		}
		else {
			temp = dfs(x - 1, y);
		}
	}
	else if (c == 'D') {
		if (x == row - 1) {
			temp = 1;
		}
		else {
			temp = dfs(x + 1, y);
		}
	}
	else if (c == 'L') {
		if (y == 0) {
			temp = 1;
		}
		else {
			temp = dfs(x, y - 1);
		}
	}
	else if (c == 'R') {
		if (y == col - 1) {
			temp = 1;
		}
		else {
			temp = dfs(x, y + 1);
		}
	}
	visited[x][y] = temp;
	return temp;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
			visited[i][j] = -1; // �ϴ� �湮�����ذɷ� �ʱ�ȭ
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == -1) { // �湮 ���������� bfs����
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == 1) { // �迭������ ������ �ִ� ��츸 üũ
				result++;
			}
		}
	}
	cout << result;
	return 0;
}