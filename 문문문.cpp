#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long n;
	int m;
	cin >> n >> m;
	if (n <= 5) {
		for (int i = 2; i <= n; i++) {
			m = (m + 1) % 2;
			cout << m << '\n';
		}
	}
	else {
		cout << "Love is open door\n";
	}
	return 0;
}