#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int alphabet[26];
int main() {
	fastio;
	string s;
	cin >> s;
	int cnt = 0, idx = -1, len = s.length();
	for (int i = 0; i < len; ++i) {
		alphabet[s[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] % 2) {
			cnt++;
			idx = i;
		}
	}
	if (cnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	string s1 = "";
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < alphabet[i] / 2; j++) {
			s1.push_back('A' + i);
		}
	}
	string s2 = s1;
	reverse(s1.begin(), s1.end());
	if (idx != -1) {
		s2.push_back('A' + idx);
	}
	cout << s2 + s1;
	return 0;
}