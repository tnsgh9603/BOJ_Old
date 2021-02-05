#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
map <string, int> mp;
int main() {
	fastio;
	int a, b, cnt = 0;
	string s;
	cin >> a >> b;
	while (a--) {
		cin >> s;
		mp[s] = 1;
	}
	while (b--) {
		cin >> s;
		if (mp[s] != 0) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}