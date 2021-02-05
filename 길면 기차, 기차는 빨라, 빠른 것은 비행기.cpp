#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int m, a, b, total;
	double A, B;
	while (1) {
		cin >> m >> a >> b;
		if (!m && !a && !b) {
			break;
		}
		A = m / (double)a * 3600;
		B = m / (double)b * 3600;
		total = round(abs(A - B));
		printf("%01d:%02d:%02d\n", total / 3600, total % 3600 / 60, total % 3600 % 60);
	}
	return 0;
}