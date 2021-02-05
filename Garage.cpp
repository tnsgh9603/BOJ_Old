#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, d; cin >> a >> b >> c >> d;
	cout << ((a / c + 1) / 2) * ((b / d + 1) / 2) << '\n';
	return 0;
}