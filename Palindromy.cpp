#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int z, l;
	cin >> z;
	while (z--) {
		bool flag = 1;
		string s;
		cin >> s; 
		l = s.length();
		for (int i = 0; flag && i < l; i++)
			if (s[i] != s[l - 1 - i]) {
				flag = 0;
			}
		if (flag) {
			cout << "1\n";
		}
		else {
			cout << "2\n";
		}
	}
	return 0;
}