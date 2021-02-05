#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map <string, int> mp;
int main() {
	fastio;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		for (int q = 1; i + q <= s.length(); q++) {
			mp[s.substr(i, q)] = 1;
		}
	}
	cout << mp.size();
	return 0;
}