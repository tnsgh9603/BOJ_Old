#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
vector <pair<int, int>> vec;
int main() {
	fastio;
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	if (c == 1) {
		cout << "0";
		return 0;
	}
	while (c--) {
		int d, e;
		cin >> d >> e;
		vec.push_back({ d,e });
	}
	int sum = 0;
	for (int i = 0; i <= vec.size() - 2; i++) {
		int diff1 = vec[i + 1].first - vec[i].first, diff2 = vec[i + 1].second - vec[i].second;
		if (diff1 * diff2 < 0) {
			sum += abs(diff1) + abs(diff2);
		}
		else {
			sum += max(abs(diff1), abs(diff2));
		}
	}
	cout << sum;
	return 0;
}