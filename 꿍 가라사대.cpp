#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string t = "Simon says";
	int n; 
	cin >> n;
	cin.ignore();
	while (n--) {
		string s;
		getline(cin, s);
		bool flag = true;
		for (int i = 0; i < 10; ++i) {
			if (s[i] != t[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			if (s.size() < 10) {
				continue;
			}
			for (int i = 10; i < s.size(); ++i) {
				cout << s[i];
			}
			cout << '\n';
		}
	}
	return 0;
}