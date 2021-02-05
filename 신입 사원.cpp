#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <pair<int, int>> vec;
		for (int i = 0, a, b; i < n; i++) {
			cin >> a >> b;
			vec.push_back({ a,b });
		}
		sort(vec.begin(), vec.end());
		int ans = 1, rank = vec[0].second;
		for (int i = 1; i < n; i++) {
			if (vec[i].second < rank) {
				ans++;
				rank = vec[i].second;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}