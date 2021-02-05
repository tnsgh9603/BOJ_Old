#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() { 
	fastio; 
	string s;
	cin >> s; 
	int cnt = 10; 
	for (int i = 1; i < s.size(); i++) {
		s[i] == s[i - 1] ? cnt += 5 : cnt += 10;
	} 
	cout << cnt;
	return 0;
}