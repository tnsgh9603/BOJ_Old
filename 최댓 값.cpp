#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[10][10];
int main() {
	fastio;
	int ans = 0, a, b;
	for (int i = 1; i <= 9; i++) {
		for (int q = 1; q <= 9; q++) {
			cin >> arr[i][q];
			if (ans < arr[i][q]) {
				ans = arr[i][q];
				a = i;
				b = q;
			}
		}
	}
	cout << ans << "\n" << a << " " << b;
	return 0;
}