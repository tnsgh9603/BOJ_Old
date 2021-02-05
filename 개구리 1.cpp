#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c;
	cin >> a >> b >> c;
	a = abs(a), b = abs(b), c = abs(c);
	if (a + b <= c) {
		if ((a + b) % 2 == 0 && c % 2 == 0) {
			cout << "YES";
		}
		else if ((a + b) % 2 != 0 && c % 2 != 0) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	else {
		cout << "NO";
	}
	return 0;
}