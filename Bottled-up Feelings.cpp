#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, v1, v2;
	cin >> n >> v1 >> v2;
	int t = (n / v1) * v1;
	while (t >= 0 && (n - t) % v2 != 0) {
		t -= v1;
	}
	if (t >= 0) {
		cout << t / v1 << ' ' << (n - t) / v2 << '\n';
	}
	else if (n % v2 == 0) {
		cout << 0 << ' ' << n / v2 << '\n';
	}
	else {
		cout << "Impossible" << '\n';
	}
	return 0;
}