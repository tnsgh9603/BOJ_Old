#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	if (!n) {
		cout << 1;
	}
	else {
		for (int i = 1; i <= 10; i++) {
			if (n < stoi(string(i, '1'))) {
				cout << i - 1;
				break;
			}
		}
	}
	return 0;
}
