#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int sol(int n) {
	int ret = 0;
	while (n > 0) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		cout << sol(sol(a) + sol(b)) << "\n";
	}
	return 0;
}