#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, r, e, c;
	cin >> n;
	while (n--) {
		cin >> r >> e >> c;
		if (r < e - c) {
			cout << "advertise\n";
		}
		else if (r == e - c) {
			cout << "does not matter\n";
		}
		else {
			cout << "do not advertise\n";
		}
	}
	return 0;
}
