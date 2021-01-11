#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	if (n % 4 == 2) {
		cout << 1;
	}
	else if (n % 4 == 0) {
		cout << 2;
	}
	else {
		cout << 0;
	}
	return 0;
}