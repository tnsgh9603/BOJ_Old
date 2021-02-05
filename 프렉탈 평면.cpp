#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k;
int recursion(int len, int x, int y) {
	if (len == 1) {
		return 0;
	}
	int border = len / n;
	//어떤 점이 한 변의 길이가 l인 평면의 가운데 k*k 영역에 속해있을 경우 이 점은 검정색으로 칠해져 있는 것이며, 
	//이를 판정하기 위해서는 border = l/n이라 했을 때, 이 점의 x 좌표와 y좌표가 [border * (n-k) / 2, border * (n-k)/2 + k) 범위 안에 들어있는지를 확인하면 된다.
	if (x >= border * (n - k) / 2 && x < border * (n + k) / 2 && y >= border * (n - k) / 2 && y < border * (n + k) / 2) {
		return 1;
	}
	return recursion(border, x % border, y % border);
}
int main() {
	fastio;
	int s, r1, r2, c1, c2;
	cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
	if (!s) {
		cout << 0;
		return 0;
	}
	int len = 1;
	while (s--) {
		len *= n;
	}
	for (int i = r1; i <= r2; i++) {
		for (int j = c1; j <= c2; j++) {
			cout << recursion(len, i, j);
		}
		cout << "\n";
	}
	return 0;
}