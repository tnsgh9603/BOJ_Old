#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	double x, tmp, total;
	cin >> x;
	while (x != 0) {
		total = 0;
		n = 2;
		while (total < x) {
			tmp = 1;
			tmp /= n;
			total += tmp;
			n++;
		}
		cout << n - 2 << " card(s)\n";
		cin >> x;
	}
	return 0;
}