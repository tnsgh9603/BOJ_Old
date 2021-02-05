#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int i, c;
int main() {
	fastio;
	string s, r = "aeiou";
	cin >> s;
	for (; i < s.size(); i++) {
		if (r.find(s[i]) != string::npos) {
			c++;
		}
	}
	cout << c;
	return 0;
}
