#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
void f(int x, int p) {
	if (x) {
		f(x / p, p);
		putchar('0' + x % p);
	}
}
int main() {
	fastio;
	int a;
	cin >> a;
	f(a, 9);
	return 0;
}