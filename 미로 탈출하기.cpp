#include <iostream>
using namespace std;
char arr[501][501];
int visited[501][501];		//-1: 방문 x, 0: 못나간다, 1: 나간다
int row, col, result = 0;

int dfs(int x, int y) {
	if (visited[x][y] != -1) {
		return visited[x][y];		// 나가거나 나가지 못하는 경우
	}
	char c = arr[x][y];
	int temp = 0;
	visited[x][y] = 0;
	if (c == 'U') { // U -> 위쪽, R -> 오른쪽, D -> 아래쪽, L-> 왼쪽
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
			visited[i][j] = -1; // 일단 방문안해준걸로 초기화
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == -1) { // 방문 안했을때만 bfs돌림
				dfs(i, j);
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j] == 1) { // 배열밖으로 나갈수 있는 경우만 체크
				result++;
			}
		}
	}
	cout << result;
	return 0;
}