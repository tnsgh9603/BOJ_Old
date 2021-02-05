#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int tmp[101];
int main() {
	fastio;
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> tmp[i];
	}
	int flag = 0, cnt = 0;
	for (int i = 1; i <= c; i++) {
		for (int j = 0; j < n; j++) {
			if (i % tmp[j] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			cnt++;
			flag = 0;
		}
	}
	cout << cnt;
	return 0;
}