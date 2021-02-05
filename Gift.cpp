#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
	fastio;
	int n, x, cnt = 0;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		if (v[i - 1] - v[i] >= x) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}