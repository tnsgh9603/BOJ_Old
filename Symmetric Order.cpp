#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s[15];
	for (int i = 1; ; i++) {
		int n;
		cin >> n;
		if (!n) {
			return 0;
		}
		for (int j = 0; j < n; j++) {
			cin >> s[j];
		}
		cout << "SET " << i << '\n';
		for (int j = 0; j < n; j += 2) {
			cout << s[j] << '\n';
		}
		for (int j = n - 1 - (n % 2); j >= 0; j -= 2) {
			cout << s[j] << '\n';
		}
	}
	return 0;
}