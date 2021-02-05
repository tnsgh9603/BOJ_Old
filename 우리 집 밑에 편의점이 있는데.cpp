#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1001];
int main() {
	fastio;
	int a, b, c, mx = 0;
	cin >> a >> b;
	while (a--) {
		cin >> c;
		arr[c]++;
	}
	for (int i = 1; i <= b; i++) {
		if (arr[i] > mx) {
			mx = arr[i];
		}
	}
	cout << mx;
	return 0;
}