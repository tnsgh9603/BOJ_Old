#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		string a, b, c;
		cin >> a;
		if (a == "#") {
			break;
		}
		cin >> b >> c;
		int diff = 0;
		cout << a << " " << b << " " << c << " ";
		for (int i = 0; i < a.size(); i++) {
			if (b[i] >= a[i]) {
				diff = abs(b[i] - a[i]);
			}
			else {
				diff = 26 - abs(b[i] - a[i]);
			}

			if (c[i] + diff <= 122) {
				cout << (char)(c[i] + diff);
			}
			else {
				cout << (char)(c[i] + diff - 26);
			}
		}
		cout << "\n";
	}
	return 0;
}