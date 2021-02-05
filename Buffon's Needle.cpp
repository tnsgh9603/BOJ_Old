#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int n, cnt = 0;
	double x, y, z, w;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z >> w;
		if ((int)x != (int)z) {
			cnt++;
		}
		else if (x * z < 0) {
			cnt++;
		}
	}
	cout << fixed << setprecision(6) << 2.0 * n / cnt;
	return 0;
}