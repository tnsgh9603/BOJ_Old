#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	int n, n1, sum = 0, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n1;
		if (n1 == 1) {
			cnt++;
			sum += cnt;
		}
		else if (n1 == 0) {
			cnt = 0;
		}
	}
	cout << sum;
}