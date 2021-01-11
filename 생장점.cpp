#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int sum = 1;
		while (n--) {
			int a, b;
			cin >> a >> b;
			sum = sum * a - b;
		}
		cout << sum << "\n";
	}
	return 0;
}