#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	vector<vector<int>> temp;
	int m = key.size(), n = lock.size();
	for (int r = 0; r < 4; r++) {
		for (int x = -m + 1; x <= n - 1; x++) {
			for (int y = -m + 1; y <= n - 1; y++) {
				//st : (x, y)
				bool flag = 1;
				for (int i = x; i < x + m && flag; i++) {
					for (int j = y; j < y + m && flag; j++) {
						if (i < 0 || i >= n || j < 0 || j >= n) {
							continue;
						}
						if (lock[i][j] == key[i - x][j - y]) {
							flag = 0;
						}
					}
				}
				for (int i = 0; i < n && flag; i++) {
					for (int j = 0; j < n && flag; j++) {
						if (x <= i && i < x + m && y <= j && j < y + m) {
							continue;
						}
						if (!lock[i][j]) {
							flag = 0;
						}
					}
				}
				if (!flag) {
					continue;
				}
				return 1;
			}
		}
		temp = lock;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				lock[j][n - 1 - i] = temp[i][j];
			}
		}
	}
	return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<vector<int>> vec;
int n, m, new_key[21][21];

void rotation(vec& key) {
	// 시계방향 90도 회전하는 코드 (인덱스 주의!)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			new_key[j][m - i - 1] = key[i][j];
		}
	}
	// 회전 후 원래 배열에 복사
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			key[i][j] = new_key[i][j];
		}
	}
}

bool solution(vec key, vec lock) {
	m = key.size(), n = lock.size();
	// 방향 최대 4번 회전
	for (int dir = 1; dir <= 4; dir++) {
		for (int y = n-2; y >= -n + 1; y--) {
			for (int x = n-2; x >= -n + 1; x--) {
				bool flag = true;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						int ny = i + y, nx = j + x;
						// key영역 밖의 인덱스에 대해서 검색할 때
						if (ny < 0 || ny >= m || nx < 0 || nx >= m) {
							// lock에 하나라도 빈 홈이 있으면
							if (lock[i][j] == 0) {
								flag = false;
							}
						}
						// key영역 안의 인덱스에 대해서 검색할 때
						else {
							// 겹쳤을 때 1이 안되는 경우
							if ((lock[i][j] + key[ny][nx] != 1)) {
								flag = false;
							}
						}
					}
				}
				// lock의 홈을 조건을 만족하며 모두 채울 수 있는 경우
				if (flag) {
					return true;
				}
			}
		}
		rotation(key);
	}
	return false;
}
*/