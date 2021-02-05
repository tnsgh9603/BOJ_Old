#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	if (n < 3) {
		cout << 1 << '\n';
	}
	else {
		cout << n - 2 << '\n';
	}
	return 0;
}