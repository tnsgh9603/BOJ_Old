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
		int ans1 = INT_MAX, ans2 = -INT_MAX, input;
		while (n--) {
			cin >> input;
			ans1 = min(ans1, input);
			ans2 = max(ans2, input);
		}
		cout << ans1 << " " << ans2 << "\n";
	}
	return 0;
}