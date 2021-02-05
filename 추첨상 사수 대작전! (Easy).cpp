#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;
	for (int a = 0; a < 99; a++) {
		for (int c = 0; c < 99; c++) {
			if (x1 == (a * seed + c) % m) {
				x1 = (a * seed + c) % m;
				if (x2 == (a * x1 + c) % m) {
					cout << a << " " << c;
					return 0;
				}
			}
		}
	}
	return 0;
}