#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, k;
	cin >> n >> k;
	while (k--) {
		int x;
		cin >> x;
		n -= ((x + 1) / 2);
	}
	if (n <= 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}