#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	string a, b; 
	cin >> a >> b;
	int cnt = 0;
	regex r(b);
	for (auto it = sregex_iterator(a.begin(), a.end(), r); it != sregex_iterator(); it++) cnt++;
	cout << cnt;
	return 0;
}