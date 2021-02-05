#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
bool arr[101][101];
int main() {
	fastio;
	for (int N = 0; N < 4; N++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int i = a; i < c; i++) {
			for (int j = b; j < d; j++) {
				arr[i][j] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			cnt += arr[i][j];
		}
	}
	cout << cnt;
	return 0;
}
