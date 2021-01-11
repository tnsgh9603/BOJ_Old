#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (a * 3 + 2 * b + c > 3 * d + 2 * e + f) {
		cout << "A";
	}
	else if (a * 3 + 2 * b + c < 3 * d + 2 * e + f) {
		cout << "B";
	}
	else {
		cout << "T";
	}
	return 0;
}