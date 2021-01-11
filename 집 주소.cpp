#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	while (1) {
		cin >> s;
		int sum = 0;
		if (s[0] == '0') {
			break;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0') {
				sum += 4;
			}
			else if (s[i] == '1') {
				sum += 2;
			}
			else {
				sum += 3;
			}
		}
		sum += s.length() + 1;
		cout << sum << "\n";
	}
	return 0;
}