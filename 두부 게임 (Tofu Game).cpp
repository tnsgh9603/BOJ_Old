#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, m, host, call;
	cin >> n >> m >> host;
	--host;
	while (1) {
		cin >> call;
		--call;
		if (call == m / 2) {
			break;
		}
		host = (host + (call - m / 2) + n) % n;
		cout << host + 1 << '\n';
	}
	cout << 0;
	return 0;
}