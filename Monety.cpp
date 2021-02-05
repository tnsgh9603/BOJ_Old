#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, t, sum = 0; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t, sum += t;
	}
	cout << min(sum, n - sum) << '\n';
	return 0;
}