#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "Alice\n";
		cout << 1 << "\n";
	}
	else {
		cout << "Bob\n";
	}
	return 0;
}