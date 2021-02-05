#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
pair<int, int> a[100001];
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a, a + n);
		cout << max_element(a, a + n, [&](pair<int, int> a, pair<int, int> b) {
			return a.first * b.second < b.first* a.second;
			})->second << "\n";
	}
	return 0;
}
