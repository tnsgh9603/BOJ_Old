#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, ans = 0, sx, sy, x, y, nx, ny;
	cin >> n >> sx >> sy;
	x = sx, y = sy;
	for (int i = 0; i < n - 1; i++) {
		cin >> nx >> ny;
		ans += abs(nx + ny - x - y);
		x = nx, y = ny;
	}
	ans += abs(x + y - sx - sy);
	cout << ans;
	return 0;
}