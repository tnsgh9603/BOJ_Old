#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int T;
	cin >> T;
	while (T--) {
		int s;
		char ch;
		cin >> s >> ch;
		for (int i = 1; i <= s; i++) {
			cout << ch;
		}
		cout << '\n';
	}
	return 0;
}