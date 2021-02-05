#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, sum = 1;
	cin >> n;
	if (n == 1) {
		cout << "1" << '\n';
		return 0;
	}
	while (sum < n) {
		sum *= 2;
	}
	if (sum == n) {
		cout << "1" << '\n';
	}
	else {
		cout << "0" << '\n';
	}
	return 0;
}