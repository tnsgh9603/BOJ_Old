#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, cnt = 0;
		cin >> n;
		for (int i = 2; i <= n; i++) {
			int c = 0;
			for (int j = i;; j *= i) {
				if (n % j != 0) { 
					break; 
				}
				c++;
			}
			cnt += c;
		}
		cout << cnt << "\n";
	}
	return 0;
}
