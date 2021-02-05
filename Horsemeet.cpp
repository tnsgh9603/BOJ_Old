#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c, d; 
	cin >> a >> b >> c >> d;
	int t = abs(c - a) + abs(d - b);
	cout << (t & 1 ? "white" : "black") << '\n';
	return 0;
}