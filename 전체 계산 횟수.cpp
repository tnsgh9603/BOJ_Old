#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	int cnt = n;
	while (n >= m) {
		n = n / m;
		cnt += n;
	}
	cout << cnt;
	return 0;
}