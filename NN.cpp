#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	string s, t = to_string(a);
	while (a--) {
		s += t;
	}
	cout << s.substr(0, b) << '\n';
	return 0;
}
