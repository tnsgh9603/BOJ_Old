#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, cnt = 0;
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		cnt += s.length();
	}
	cout << cnt;
	return 0;
}