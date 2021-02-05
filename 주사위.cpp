#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, x, y, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		printf("Case %d: %d\n", i + 1, x + y);
	}
}