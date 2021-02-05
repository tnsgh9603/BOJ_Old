#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int d, m, y;
	vector<int> v{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> d >> m >> y && (d || m || y)) {
		bool flag = 1;
		bool t = (y % 4 == 0 && y % 100 || y % 400 == 0);
		if (d < 1 || m < 1 || m > 12) {
			flag = 0;
		}
		else if (m == 2 && d == 29) {
			flag = t;
		}
		else if (v[m] < d) {
			flag = 0;
		}
		cout << (flag ? "Valid" : "Invalid") << '\n';
	}
	return 0;
}