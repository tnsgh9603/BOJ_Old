#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s;
	cin >> s;
	if (s[0] == '5' && s[1] == '5' && s[2] == '5') {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}