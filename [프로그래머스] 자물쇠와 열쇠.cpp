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
	// �ð���� 90�� ȸ���ϴ� �ڵ� (�ε��� ����!)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			new_key[j][m - i - 1] = key[i][j];
		}
	}
	// ȸ�� �� ���� �迭�� ����
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			key[i][j] = new_key[i][j];
		}
	}
}

bool solution(vec key, vec lock) {
	m = key.size(), n = lock.size();
	// ���� �ִ� 4�� ȸ��
	for (int dir = 1; dir <= 4; dir++) {
		for (int y = n-2; y >= -n + 1; y--) {
			for (int x = n-2; x >= -n + 1; x--) {
				bool flag = true;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						int ny = i + y, nx = j + x;
						// key���� ���� �ε����� ���ؼ� �˻��� ��
						if (ny < 0 || ny >= m || nx < 0 || nx >= m) {
							// lock�� �ϳ��� �� Ȩ�� ������
							if (lock[i][j] == 0) {
								flag = false;
							}
						}
						// key���� ���� �ε����� ���ؼ� �˻��� ��
						else {
							// ������ �� 1�� �ȵǴ� ���
							if ((lock[i][j] + key[ny][nx] != 1)) {
								flag = false;
							}
						}
					}
				}
				// lock�� Ȩ�� ������ �����ϸ� ��� ä�� �� �ִ� ���
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