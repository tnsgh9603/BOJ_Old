#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int num[101];
int main() {
	fastio;
	int i, n;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> num[i];
		num[i] *= i;
	}
	for (i = 1; i <= n; i++) {
		cout << num[i] - num[i - 1] << " ";
	}
	return 0;
}
