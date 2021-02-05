#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int h, m, s, q;
	cin >> h >> m >> s >> q;
	while (q--) {
		int T;
		cin >> T;
		if (T == 1 || T == 2) {
			int c;
			cin >> c;
			if (T == 2) {
				c *= -1;
			}
			h += c / 3600;
			c %= 3600;
			m += c / 60;
			c %= 60;
			s += c;
			while (s < 0) {
				s += 60;
				--m;
			}
			while (m < 0) {
				m += 60;
				--h;
			}
			while (h < 0)
				h += 24;
			//¿Ã¸²
			while (s > 59) {
				s -= 60;
				++m;
			}
			while (m > 59) {
				m -= 60;
				++h;
			}
			while (h > 23) {
				h -= 24;
			}
		}
		else {
			cout << h << ' ' << m << ' ' << s << '\n';
		}
	}
	return 0;
}