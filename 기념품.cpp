#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[5001];
int main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		arr[i] = (arr[i - 1] + (n - i + 1) * (n - i + 1) % i * (n - i + 1)) % i;
	}
	cout << arr[n] + 1;
	return 0;
}