#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;;
int main() {
	fastio;
	int n, m, a, b, d;
	cin >> n >> m >> a >> b;
	for (n = a; m--;) {
		cin >> d;
		if (n <= d) {
			n = n == a ? b : a;
		}
	}
	cout << n;
	return 0;
}