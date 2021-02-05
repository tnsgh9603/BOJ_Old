#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int s, x;
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < n) {
			s += n - a;
		}
		if (x < n - a) {
			x = n - a;
		}
	}
	cout << s - x;
	return 0;
}
