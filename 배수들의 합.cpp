#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
bool ismul[1001];
int n, m, a, ans;
int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		for (int j = a; j <= n; j += a) {
			ismul[j] = true;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (ismul[i]) {
			ans += i;
		}
	}
	cout << ans;
	return 0;
}
