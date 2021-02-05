#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N;
	cin >> N;
	while (N--) {
		int n;
		cin >> n;
		bool flag = 0;
		if (n < 10) {
			if (n * n % 10 == n) {
				flag = 1;
			}
		}
		else if (n < 100) {
			if (n * n % 100 == n) {
				flag = 1;
			}
		}
		else if (n < 1000) {
			if (n * n % 1000 == n) {
				flag = 1;
			}
		}
		cout << (flag ? "YES" : "NO") << "\n";
	}
	return 0;
}
