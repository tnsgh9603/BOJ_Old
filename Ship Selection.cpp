#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int tc, n, d, v, f, c;
	cin >> tc;
	while (tc--) {
		cin >> n >> d; 
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> v >> f >> c;
			if (d * c <= f * v) {
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}