#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool ans[101];
int main() {
	fastio;
	int n, m, arr[123];
	cin >> n >> m;
	arr[0] = 0;
	for (int i = 1; i <= m; ++i) {
		cin >> arr[i];
	}
	arr[m + 1] = n;
	for (int i = 0; i <= m + 1; ++i) {
		for (int j = i + 1; j <= m + 1; ++j) {
			ans[arr[j] - arr[i]] = 1;
		}
	}
	for (int i = 1; i <= n; ++i){
		if (ans[i]) {
			cout << i << ' ';
		}
	}
	return 0;
}