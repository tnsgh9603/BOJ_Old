#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, ans = 0;
	string time[4];
	for (int i = 0; i < 4; ++i) {
		cin >> time[i];
		if (time[i].size() == 1)
			time[i] = '0' + time[i];
	}
	cin >> n;
	string& h = time[0], & m = time[1];
	bool flag = false;
	for (char c : {h[0], h[1], m[0], m[1]})
		if (c == n + '0') flag = true;
	ans += flag;
	while (h != time[2] || m != time[3]) {
		++m[1];
		if (m[1] == '9' + 1) {
			m[1] = '0';
			++m[0];
		}
		if (m[0] == '5' + 1) {
			m[0] = '0';
			++h[1];
		}
		if (h[1] == '9' + 1) {
			h[1] = '0';
			++h[0];
		}
		flag = false;
		for (char c : {h[0], h[1], m[0], m[1]})
			if (c == n + '0') flag = true;
		ans += flag;
	}
	cout << ans;
	return 0;
}