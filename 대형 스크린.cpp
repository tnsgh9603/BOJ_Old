#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int solve(int x1, int y1, int x2, int y2) {
	return max((x2 + x1 - 1) / x1, (y2 + y1 - 1) / y1);
}
int main() {
	fastio;
	int rh, rv, sh, sv;
	cin >> rh >> rv >> sh >> sv;
	int q;
	cin >> q;
	long long ret = 1e18;
	while (q--) {
		int irh, irv, ish, isv, p;
		cin >> irh >> irv >> ish >> isv >> p;
		long long vert = solve(irh, ish, rh, sh) * solve(irv, isv, rv, sv);
		swap(irh, irv);
		swap(ish, isv);
		long long vert2 = solve(irh, ish, rh, sh) * solve(irv, isv, rv, sv);
		ret = min(ret, min(vert * p, vert2 * p));
	}
	cout << ret << "\n";
	return 0;
}
