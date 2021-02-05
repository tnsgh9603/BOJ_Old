#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	vector<int> v(10), w(10);
	for (int i = 0; i < 10; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < 10; i++) {
		cin >> w[i];
	}
	int cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (v[i] != w[i]) {
			cnt += 2 * (v[i] > w[i]) - 1;
		}
	}
	if (!cnt) {
		cout << 'D';
	}
	else {
		cnt > 0 ? cout << 'A' : cout << 'B';
	}
	return 0;
}
