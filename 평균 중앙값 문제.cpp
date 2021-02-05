#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
	fastio;
	int a, b;
	while (cin >> a >> b && !(!a && !b)) {
		cout << min({ 2 * b - a , (a + b) / 2 , 2 * a - b }) << '\n';
	}
	return 0;
}