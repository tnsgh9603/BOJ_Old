#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long n;
	int k, q;
	cin >> n >> k >> q;
	long long int y, x;
	for (int i = 0; i < q; ++i) {
		cin >> y >> x;
		long long int dist = 0;
		if (k == 1) {
			dist = abs(y - x);
		}
		else {
			while (y != x) {
				if (y > x) {
					y = (y - 2) / k + 1;
				}
				else {
					x = (x - 2) / k + 1;
				}
				++dist;
			}
		}
		cout << dist << '\n';
	}
	return 0;
}