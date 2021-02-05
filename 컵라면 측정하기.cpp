#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int k, d1, d2;
	cin >> k >> d1 >> d2;
	if (d1 == d2) {
		cout << k * k << '\n';
	}
	else {
		float tmp = (float)(d1 - d2) / 2;
		cout << fixed << setprecision(6) << k * k - tmp * tmp << '\n';
	}
	return 0;
}
