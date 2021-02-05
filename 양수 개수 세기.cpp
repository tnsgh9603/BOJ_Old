#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n = 0, cnt = 0;
	while (cin >> n) {
		if (n > 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}