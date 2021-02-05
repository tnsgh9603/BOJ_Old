#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int a, b, n;
		cin >> a >> b >> n;
		vector<pair<int, int>> v(n);
		vector<int> B(a + 1), G(b + 1);
		for (int i = 0; i < n; i++) {
			cin >> v[i].first;
			B[v[i].first]++;
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i].second;
			G[v[i].second]++;
		}

		long long cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			cnt += n - (B[x] + G[y] - 1);
		}
		cout << cnt / 2 << "\n";
	}
	return 0;
}