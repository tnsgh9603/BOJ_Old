#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, d, k; 
	cin >> a >> d >> k; 
	if ((k - a) % d || (k - a) / d < 0) {
		cout << "X\n";
	}
	else {
		cout << (k - a) / d + 1 << "\n";
	}
	return 0;
}