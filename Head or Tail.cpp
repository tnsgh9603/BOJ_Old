#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		int t;
		cin >> t;
		if (!t) {
			break;
		}
		int ret[2] = { 0,0 };
		while (t--) {
			int n;
			cin >> n;
			ret[n]++;
		}
		cout << "Mary won " << ret[0] << " times and John won " << ret[1] << " times\n";
	}
	return 0;
}