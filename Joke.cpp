#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	int ans = 0;
	while (getline(cin, s))	{
		while (s.find("joke") != -1) {
			ans++;
			s = s.substr(s.find("joke") + 4);
		}
	}
	cout << ans;
	return 0;
}