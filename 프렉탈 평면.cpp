#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, k;
int recursion(int len, int x, int y) {
	if (len == 1) {
		return 0;
	}
	int border = len / n;
	//� ���� �� ���� ���̰� l�� ����� ��� k*k ������ �������� ��� �� ���� ���������� ĥ���� �ִ� ���̸�, 
	//�̸� �����ϱ� ���ؼ��� border = l/n�̶� ���� ��, �� ���� x ��ǥ�� y��ǥ�� [border * (n-k) / 2, border * (n-k)/2 + k) ���� �ȿ� ����ִ����� Ȯ���ϸ� �ȴ�.
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