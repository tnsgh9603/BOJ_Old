#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mat[301][301]; //페이지의 장마다 숫자를 입력, 행은 장, 열은 각 페이지 장의 있는 숫자들의 순서
int n, m; //n은 총 페이지 수, m은 사라진 숫자
int main() {
	fastio;
	while (1) {
		int cnt = 1; //페이지의 숫자를 넣어줄 변수
		bool flag = false; //flag를 이용하여 반복문을 탈출할 수 있게 한다.
		fill(&mat[0][0], &mat[300][300], 0); //0으로 초기화
		cin >> n;
		if (n == 0) { //0입력시
			break; //종료
		}
		cin >> m;

		//페이지의 숫자를 넣는 과정, 규칙을 이용하였다.
		for (int i = 1; i <= n / 4; i++) {
			mat[i][1] = cnt;
			mat[i][2] = cnt + 1;
			mat[i][3] = (n + 1) - (cnt + 1);
			mat[i][4] = (n + 1) - cnt;
			cnt = cnt + 2;
		}

		//주어진 공간에서 해당 숫자가 어디 페이지에 있는지 찾은 후 그 페이지의 숫자들을 출력한다.
		for (int i = 1; i <= n / 4; i++) {
			for (int j = 1; j <= 4; j++) {
				if (mat[i][j] == m) {
					flag = true;
					for (int k = 1; k <= 4; k++) {
						if (mat[i][k] == m) { //찾는 수면
							continue; //건너뛴다.
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