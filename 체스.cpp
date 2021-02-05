#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N; 
	cin >> N;
	while (N--) {
		string s; 
		int b; 
		cin >> s >> b;
		int a = s[0] - 'A' + 1 + 8 * (s[1] - '0' - 1);
		--a, --b;
		bool flag1 = (a % 8 + a / 8) & 1;
		bool flag2 = (b % 8 + b / 8) & 1;
		cout << (flag1 ^ flag2 ? "NO" : "YES") << '\n';
	}
	return 0;
}
