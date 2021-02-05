#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, p;
	cin >> n >> p;
	if (p >= n / 3 + 1 && p <= n - (n + 1) / 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}