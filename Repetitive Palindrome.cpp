#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string s;
int find() {
	int len = s.length();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	fastio; 
	cin >> s;
	find() ? cout << "YES" : cout << "NO";
	return 0;
}