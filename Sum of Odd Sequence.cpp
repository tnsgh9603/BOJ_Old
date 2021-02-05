#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int m[101];
int calc(int oddNum) {
	if (oddNum == 1) {
		return 1;
	}
	if (!m[oddNum]) {
		m[oddNum] = calc(oddNum - 2) + oddNum;
	}
	return m[oddNum];
}
int main() {
	fastio;
	int t, in;
	cin >> t;
	while (t--) {
		cin >> in;
		cout << calc(in) << "\n";
	}
	return 0;
}