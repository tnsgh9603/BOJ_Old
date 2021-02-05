#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int t;
	cin >> t;
	while (1) {
		long long a;
		cin >> a;
		cout << a % 2020 << " " << a / 2020 << " ";
		if (a % 2020 <= a / 2020) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}