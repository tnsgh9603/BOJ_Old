#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
	fastio;
	string a, b;
	cin >> a >> b;
	int n = 0, m = 0;
	n += stoi(a.substr(0, 2)) * 3600;
	n += stoi(a.substr(3, 2)) * 60;
	n += stoi(a.substr(6, 2));
	m += stoi(b.substr(0, 2)) * 3600;
	m += stoi(b.substr(3, 2)) * 60;
	m += stoi(b.substr(6, 2));
	m += 3600 * 24;
	int ans = m - n; ans %= 3600 * 24;
	if (!ans) {
		ans = 3600 * 24;
	}
	int H = ans / 3600;
	int M = ans % 3600 / 60;
	int S = ans % 60;
	cout << string(H < 10, '0') << H << ':' << string(M < 10, '0') << M << ':' << string(S < 10, '0') << S;
	return 0;
}