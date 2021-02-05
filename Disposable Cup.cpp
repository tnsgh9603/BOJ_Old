#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, n;
	cin >> a >> b >> n;
	for (int i = 1; i <= n; i++) {
		cout << a * n + b * i << ' ';
	}
	return 0;
}