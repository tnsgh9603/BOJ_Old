#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int a, b;
	cin >> a >> b;
	while (a != 0 || b != 0) {
		int i = 1;
		while (1) {
			if (pow(i, b) >= a) {
				if (pow(i, b) - a > a - pow(i - 1, b)) {
					cout << i - 1 << "\n";
				}
				else {
					cout << i << "\n";
				}
				break;
			}
			i++;
		}
		cin >> a >> b;
	}
	return 0;
}