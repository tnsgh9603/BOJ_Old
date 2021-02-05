#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	while (cin >> n) {
		if (!n) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				cout << '*';
			}
			cout << '\n';
		}
	}
	return 0;
}