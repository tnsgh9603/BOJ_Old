#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		for (int i = 0; i < 30; i++) {
			if (num & (1 << i)) {
				cout << i << ' ';
			}
		}
	}
	return 0;
}