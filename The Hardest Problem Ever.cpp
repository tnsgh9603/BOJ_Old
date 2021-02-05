#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string key = "VWXYZABCDEFGHIJKLMNOPQRSTU";
int main() {
	fastio;
	string s;
	while (1) {
		cin >> s;
		if (s[0] == 'E') {
			break;
		}
		cin.ignore();
		getline(cin, s);
		for (auto& c : s) {
			if (isalpha(c)) {
				c = key[c - 'A'];
			}
			cout << c;
		}
		cout << '\n';
		cin >> s;
	}
	return 0;
}