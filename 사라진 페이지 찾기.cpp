#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mat[301][301]; //�������� �帶�� ���ڸ� �Է�, ���� ��, ���� �� ������ ���� �ִ� ���ڵ��� ����
int n, m; //n�� �� ������ ��, m�� ����� ����
int main() {
	fastio;
	while (1) {
		int cnt = 1; //�������� ���ڸ� �־��� ����
		bool flag = false; //flag�� �̿��Ͽ� �ݺ����� Ż���� �� �ְ� �Ѵ�.
		fill(&mat[0][0], &mat[300][300], 0); //0���� �ʱ�ȭ
		cin >> n;
		if (n == 0) { //0�Է½�
			break; //����
		}
		cin >> m;

		//�������� ���ڸ� �ִ� ����, ��Ģ�� �̿��Ͽ���.
		for (int i = 1; i <= n / 4; i++) {
			mat[i][1] = cnt;
			mat[i][2] = cnt + 1;
			mat[i][3] = (n + 1) - (cnt + 1);
			mat[i][4] = (n + 1) - cnt;
			cnt = cnt + 2;
		}

		//�־��� �������� �ش� ���ڰ� ��� �������� �ִ��� ã�� �� �� �������� ���ڵ��� ����Ѵ�.
		for (int i = 1; i <= n / 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (mat[i][j] == m) {
					flag = true;
					for (int k = 1; k <= 4; k++) {
						if (mat[i][k] == m) { //ã�� ����
							continue; //�ǳʶڴ�.
						}
						cout << mat[i][k] << ' ';
					}
					cout << '\n';
					break;
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	return 0;
}