#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	bitset<100000> a, b, t;
	cin >> a >> b;
	t = a & b; cout << t << '\n';
	t = a | b; cout << t << '\n';
	t = a ^ b; cout << t << '\n';
	t = ~a; cout << t << '\n';
	t = ~b; cout << t << '\n';
	return 0;
}