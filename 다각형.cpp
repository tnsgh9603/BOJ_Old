#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long a, b, sum = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (i == 2) {
			continue;
		}
		if (i % 2 == 0) {
			sum += i;
		}
	}
	cout << sum;
	return 0;
}