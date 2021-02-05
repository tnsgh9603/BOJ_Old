#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	int t = 0,ans = 0;
	string s;
	getline(cin, s);
	for (int a0 = 0; a0 < n; ++a0) {
		getline(cin, s);
		for (char c : s) {
			if (c == 'T' || c == 't') {
				++t;
			}
			else if (c == 'S' || c == 's') {
				++ans;
			}
		}
	}
	cout << ((t > ans) ? "English" : "French");
	return 0;
}