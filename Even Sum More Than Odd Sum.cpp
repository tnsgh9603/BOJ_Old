#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		int t;
		cin >> t;
		int od = 0, ev = 0;
		for (int j = 0; j < t; ++j) {
			int n;
			cin >> n;
			if (n % 2) {
				od += n;
			}
			else {
				ev += n;
			}
		}
		if (ev == od) {
			cout << "TIE\n";
		}
		else if (ev > od) {
			cout << "EVEN\n";
		}
		else {
			cout << "ODD\n";
		}
	}
	return 0;
}