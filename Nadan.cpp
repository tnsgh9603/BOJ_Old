#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, m; 
	cin >> n >> m;
	for (int i = 0; i < m - 1; i++) {
		cout << i + 1 << '\n';
	}
	cout << n - (m * (m - 1) / 2) << '\n';
	return 0;
}