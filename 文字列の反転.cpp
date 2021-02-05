#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, a, b;
	string s, s2;
	cin >> n >> a >> b >> s;
	if (a != b) {
		for (int i = a - 1; i < b; i++) {
			s2 += s[i];
		}
		reverse(s2.begin(), s2.end());
		s.replace(a - 1, b - a + 1, s2);
	}
	cout << s;
	return 0;
}