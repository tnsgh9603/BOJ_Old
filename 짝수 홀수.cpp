#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	long long n;
	cin >> t;
	while (t--) {
		cin >> n;
		long long sn = sqrt(n);
		cout << (sn * sn == n || (sn + 1) * (sn + 1) == n) << ' ';
	}
	return 0;
}