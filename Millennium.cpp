#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int getday(int y, int m, int d) {
	int ret = 0;
	ret += (y - 1) * 195;
	ret += (y - 1) / 3 * 5;
	ret += (m - 1) * 20;
	if (y % 3 != 0) {
		ret -= (m - 1) / 2;
	}
	ret += d;
	return ret;
}
int main() {
	fastio;
	int T;
	cin >> T;
	while (T--) {
		int y, m, d;
		cin >> y >> m >> d;
		cout << getday(1000, 1, 1) - getday(y, m, d) << '\n';
	}
	return 0;
}