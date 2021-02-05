#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	if (n <= 5) {
		cout << n / 2 + 1;
	}
	else {
		cout << n / 2 + 1 - (n - 5);
	}
	return 0;
}