#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string s1 = to_string(a) + to_string(b), s2 = to_string(c) + to_string(d);
	long long n1 = stoll(s1);
	long long n2 = stoll(s2);
	cout << n1 + n2 << '\n';
	return 0;
}