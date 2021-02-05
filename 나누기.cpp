#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, f;
	cin >> n >> f;
	n -= n % 100;
	while (1) {
		if (n % f == 0) {
			break;
		}
		n++;
	}
	cout << setw(2) << setfill('0') << n % 100 << '\n';
	return 0;
}