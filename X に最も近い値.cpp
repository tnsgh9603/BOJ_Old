#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c, ans = 0, temp = INT_MAX;
	cin >> a >> b >> c;
	for (int i = b; i <= c; i++) {
		if (abs(a - i) < temp) {
			temp = abs(a - i);
			ans = i;
		}
	}
	cout << ans;
	return 0;
}