#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int cnt, y = 0, n = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int ans;
		cin >> ans;
		if (ans == 0) {
			n += 1;
		}
		else {
			y += 1;
		}
	}
	if (n > y) {
		cout << "Junhee is not cute!";
	}
	else {
		cout << "Junhee is cute!";
	}
	return 0;
}