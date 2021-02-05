#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
double arr[1001];
int main() {
	fastio;
	double w;
	while (1) {
		int n, m, i, f;
		cin >> n >> m >> w;
		if (!n && !m) {
			break;
		}
		f = 0;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] > w) {
				break;
			}
		}
		if (i == n && arr[0] <= w / 2 && arr[n - 1] >= 75 - w / 2) {
			f++;
		}
		swap(n, m);
		for (i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (i = 1; i < n; i++) {
			if (arr[i] - arr[i - 1] > w) {
				break;
			}
		}
		if (i == n && arr[0] <= w / 2 && arr[n - 1] >= 100 - w / 2) {
			f++;
		}
		if (f > 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}