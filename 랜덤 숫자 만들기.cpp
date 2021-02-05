#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, k, s;
	while (cin >> a && a) {
		int c[10001] = { 0 };
		for (s = 0; !c[a]; s++) {
			c[a] = 1;
			k = a * a;
			a = k / 100 % 10000;
		}
		cout << s << "\n";
	}
	return 0;
}