#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b, c;
	long long sum = 0;
	cin >> a >> b;
	c = a + b;
	while (c--) {
		cin >> a;
		sum += a;
	}
	cout << sum;
	return 0;
}