#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if (a > c) {
		swap(a, c);
	}
	if (b > c) {
		swap(b, c);
	}
	if (a > b) {
		swap(a, b);
	}
	if (d > f) {
		swap(d, f);
	}
	if (e > f) {
		swap(e, f);
	}
	if (d > e) {
		swap(d, e);
	}
	if (a == d && b == e && c == f && a * a + b * b == c * c) {
		cout << "YES" << '\n';
	}
	else {
		cout << "NO" << '\n';
	}
	return 0;
}