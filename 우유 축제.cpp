#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	int m[1000], max = 0, c = 0;

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	for (int j = 0; j < n; j++) {
		if (m[j] == 0 && c == 0) {
			max++;
			c = 1;
		}
		if (m[j] == 1 && c == 1) {
			max++;
			c = 2;
		}
		if (m[j] == 2 && c == 2) {
			max++;
			c = 0;
		}
	}

	cout << max;
	return 0;
}