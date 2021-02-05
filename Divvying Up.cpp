#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long n, t, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t, sum += t;
	}
	cout << (sum % 3 ? "no" : "yes") << '\n';
	return 0;
}