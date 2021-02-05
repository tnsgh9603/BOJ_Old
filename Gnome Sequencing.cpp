#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, a, b, c;
	cin >> n;
	cout << "Gnomes:\n";
	while (n--) {
		cin >> a >> b >> c;
		(a < b&& c < b) || (a > b && c > b) ? cout << "Unordered\n" : cout << "Ordered\n";
	}
	return 0;
}
