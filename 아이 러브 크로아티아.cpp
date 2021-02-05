#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int k, q, time = 0;
	cin >> k >> q;
	while (q--) {
		int t;
		char ans;
		cin >> t >> ans;
		time += t;
		if (time >= 210) {
			cout << k;
			break;
		}
		if (ans == 'T') {
			k++;
			if (k == 9) {
				k = 1;
			}
		}
	}
	return 0;
}