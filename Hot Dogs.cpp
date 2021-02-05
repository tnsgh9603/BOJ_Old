#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int h, p;
	while (cin >> h >> p) {
		double ans = (double)h / (double)p;
		cout << fixed << setprecision(2) << ans << "\n";
	}
	return 0;
}