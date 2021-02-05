#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int T;
	cin >> T;
	int korea = 0, yonsei = 0;
	for (int i = 0; i < T; i++) {
		int x[9];
		int y[9];
		for (int j = 0; j < 9; j++) {
			cin >> x[j] >> y[j];
		}
		for (int k = 0; k < 9; k++) {
			yonsei += x[k];
			korea += y[k];
		}
		if (korea > yonsei) {
			cout << "Korea" << '\n';
		}
		else if (yonsei > korea) {
			cout << "Yonsei" << '\n';
		}
		else if (yonsei == korea) {
			cout << "Draw" << '\n';
		}
	}
	return 0;
}