#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
double getAVG(int f, int e) {
	double ret = 0;
	for (int i = f; i <= e; i++) ret += i;
	ret /= (e - f + 1);
	return ret;
}
int main() {
	fastio;
	int a, b, c, d, q, w, e, r;
	cin >> a >> b >> c >> d >> q >> w >> e >> r;
	double z = getAVG(a, b), x = getAVG(c, d), h = getAVG(q, w), v = getAVG(e, r);
	if (z + x == h + v) {
		cout << "Tie" << "\n";
	}
	else if (z + x > h + v) {
		cout << "Gunnar" << "\n";
	}
	else {
		cout << "Emma" << "\n";
	}
	return 0;
}