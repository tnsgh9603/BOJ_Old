#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long n, p, ans = 1;
	cin >> n >> p;
	for (int i = 1; i <= n; i++) {
		ans = (ans * i) % p;
	}
	cout << ans;
	return 0;
}
