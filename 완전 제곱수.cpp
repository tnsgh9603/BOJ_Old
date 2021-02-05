#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int ans = 0, n;
	cin >> n;
	for (int i = 1; i <= 500; i++) {
		for (int j = i; j <= 500; j++) {
			if (j * j == i * i + n) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}