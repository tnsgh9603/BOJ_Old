#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long arr[10000001];
int main() {
	fastio;
	int n;
	cin >> n;
	arr[1] = 5;
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + (i + 1) * 3 - 2;
	}
	cout << arr[n] % 45678;
	return 0;
}