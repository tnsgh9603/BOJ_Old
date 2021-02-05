#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= 8;
	}
	cout << ans;
	return 0;
}