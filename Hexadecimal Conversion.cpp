#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	int len = s.size();
	vector<int> vt(2 * len);
	for (int i = 0; i < len; i++) {
		int pos = len - 1 - i, val;
		if (s[pos] <= '9') {
			val = s[pos] - '0';
		}
		else {
			val = s[pos] - 'A' + 10;
		}
		int ex = 4 * i;
		vt[ex / 3] += pow(2, ex % 3) * val;
	}
	for (int i = 0; i < 2 * len; i++) {
		if (vt[i] > 7) {
			vt[i + 1] += vt[i] / 8;
			vt[i] %= 8;
		}
	}
	while (!vt.back() && vt.size() != 1) {
		vt.pop_back();
	}
	auto it = vt.end();
	while (it != vt.begin()) {
		cout << *--it;
	}
	return 0;
}