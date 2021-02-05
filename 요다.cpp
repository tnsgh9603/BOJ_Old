#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string s, a, b, t; 
		getline(cin, s);
		stringstream in(s);
		in >> a >> b;
		while (in >> t) {
			cout << t << ' ';
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}