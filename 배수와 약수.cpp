#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		int x, y;
		cin >> x >> y;
		if (!x && !y) {
			break;
		}
		if (y % x == 0) {
			cout << "factor" << endl;
		}
		else if (x % y == 0) {
			cout << "multiple" << endl;
		}
		else {
			cout << "neither" << endl;
		}
	}
	return 0;
}