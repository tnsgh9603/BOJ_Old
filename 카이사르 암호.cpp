#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string s; 
	cin >> s;
	for (auto i : s) {
		cout << char('A' + (i - 'A' + 23) % 26);
	}
	return 0;
}