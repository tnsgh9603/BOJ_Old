#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, cnt = 0;
	bool flag = 0;
	cin >> n;
	for (int i = 1; i <= sqrt(n); i++) {
		if (i * i == n) {
			flag = 1;
			break;
		}
		if (n % i == 0) {
			cnt++;
		}
	}
	if (flag) {
		cout << cnt * 2 + 1;
	}
	else {
		cout << cnt * 2;
	}
	return 0;
}