#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int N, i; main() { 
	fastio;
	for (cin >> N; N--;) {
		string s; 
		cin >> i >> s; 
		cout << s.erase(i - 1, 1) << '\n';
	} 
	return 0;
}
