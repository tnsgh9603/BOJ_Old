#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int ts, x, y, z;
	cin >> ts;
	while (ts--) {
		cin >> x >> y;
		z = x - 2 - y;
		z *= -1;
		cout << z << "\n";
	}
	return 0;
}