#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[101], b[101];
int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i] - 1]++;
	}
	sort(b, b + m);
	cout << b[m - 1];
	return 0;
}