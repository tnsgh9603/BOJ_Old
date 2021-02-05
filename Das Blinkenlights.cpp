#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int gcd(int x, int y) { 
	return y == 0 ? x : gcd(y, x % y);
}
int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int g = gcd(x, y);
	if (x * y / g > z) {
		cout << "no";
	}
	else {
		cout << "yes";
	}
	return 0;
}