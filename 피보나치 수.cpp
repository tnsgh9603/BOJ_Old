#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[46];
int main() {
	fastio;
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= 45; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n;
	cin >> n;
	cout << arr[n];
	return 0;
}