#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void solve1(string s) {
	cout << s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == '_') {
			cout << (char)toupper(s[++i]);
		}
		else {
			cout << s[i];
		}
	}
	cout << '\n';
}
void solve2(string s) {
	cout << s[0];
	for (int i = 1; i < s.size(); ++i) {
		if (isupper(s[i])) {
			cout << '_' << (char)tolower(s[i]);
		}
		else {
			cout << s[i];
		}
	}
	cout << '\n';
}

int main() {
	fastio;
	int n;
	string s;
	cin >> n >> s;
	s[0] = tolower(s[0]);
	solve1(s);
	solve2(s);
	s[0] = toupper(s[0]);
	solve1(s);
	return 0;
}