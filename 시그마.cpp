#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long a,b;
	cin >> a >> b; 
	if (a > b) {
		swap(a, b);
	}
	cout << (a + b) * (b - a + 1) / 2;
	return 0;
}