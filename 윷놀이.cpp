#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	for (int i = 0; i < 3; ++i) {
		int a, cnt1 = 0, cnt2 = 0;
		for (int q = 0; q < 4; ++q) {
			cin >> a;
			if (a == 0) {
				cnt1++;
			}
		}
		if (cnt1 == 0) {
			cout << "E\n";
		}
		if (cnt1 == 1) {
			cout << "A\n";
		}
		if (cnt1 == 2) {
			cout << "B\n";
		}
		if (cnt1 == 3) {
			cout << "C\n";
		}
		if (cnt1 == 4) {
			cout << "D\n";
		}
	}
	return 0;
}