#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a, b, i; main() {
	fastio;
	string s, r;
	cin >> s;
	for (; i < s.size() - 2; i++) {
		r = s.substr(i, 3);
		if (r == "IOI") {
			a++;
		}
		if (r == "JOI") {
			b++;
		}
	}
	cout << b << '\n' << a;
	return 0;
}

