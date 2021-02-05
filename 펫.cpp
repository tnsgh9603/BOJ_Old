#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int o, w, x;
	string s;
	for (int t = 1;; t++) {
		cin >> o >> w;
		if (!o && !w) {
			return 0;
		}
		bool f = true;
		while (1) {
			cin >> s >> x;
			if (s == "#" && x == 0) {
				break;
			}
			if (s == "F") {
				w += x;
			}
			else {
				w -= x;
			}
			if (w <= 0) {
				f = false;
			}
		}
		cout << t << " ";
		if (!f) {
			cout << "RIP";
		}
		else if (o / 2 < w && w < 2 * o) {
			cout << ":-)";
		}
		else {
			cout << ":-(";
		}
		cout << "\n";
	}
	return 0;
}