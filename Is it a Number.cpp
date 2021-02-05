#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		regex r(R"(\s*\d+\s*)");
		if (!regex_match(s, r)) {
			cout << "invalid input" << '\n';
		}
		else {
			stringstream in(s);
			in >> s;
			while (s.size() > 1 && s[0] == '0') {
				s.erase(0, 1);
			}
			cout << s << '\n';
		}
	}
	return 0;
}