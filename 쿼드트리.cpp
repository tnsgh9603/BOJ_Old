#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int mp[65][65];
void recursion(int x, int y, int size) {
	if (size == 1) {
		cout << mp[x][y];
		return;
	}
	bool onlyone = 1, onlyzero = 1;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (!mp[i][j]) {
				onlyone = 0;
			}
			if (mp[i][j]) {
				onlyzero = 0;
			}
		}
	}
	if (onlyzero) {
		cout << 0;
		return;
	}
	if (onlyone) {
		cout << 1;
		return;
	}
	cout << "(";
	recursion(x, y, size / 2);
	recursion(x, y + size / 2, size / 2);
	recursion(x + size / 2, y, size / 2);
	recursion(x + size / 2, y + size / 2, size / 2);
	cout << ")";
}
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= s.length(); j++) {
			mp[i][j] = s[j - 1] - '0';
		}
	}
	recursion(1, 1, n);
	return 0;
}