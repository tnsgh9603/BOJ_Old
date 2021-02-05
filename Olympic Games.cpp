#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n;
	while (cin >> n && n) {
		if (n == 1916 || n == 1940 || n == 1944) {
			cout << n << " Games cancelled\n";
		}
		else if (n == 2024 || n == 2028) {
			cout << n << " No city yet chosen\n";
		}
		else if (n<1896 || n % 4) {
			cout << n << " No summer games\n";
		}
		else {
			cout << n << " Summer Olympics\n";
		}
	}
	return 0;
}