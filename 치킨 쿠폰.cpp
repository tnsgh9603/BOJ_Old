#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int n, k, answer, stamp;
	while (cin >> n >> k) {
		answer = stamp = 0;
		while (n) {
			answer += n;
			stamp += n;
			n = stamp / k;
			stamp %= k;
		}
		cout << answer << "\n";
	}
	return 0;
}