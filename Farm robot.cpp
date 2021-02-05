#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[101];
int main() {
	fastio;
	int a, b, c, n, ans = 1;
	arr[1]++;
	cin >> a >> b >> c;
	for (int i = 0; i < b; ++i) {
		cin >> n;
		if (n == 1) {
			ans++;
		}
		else if (n == -1) {
			ans--;
		}
		if (ans == 0) {
			ans = a;
		}
		else if (ans == a + 1) {
			ans = 1;
		}
		arr[ans]++;
	}
	cout << arr[c];
	return 0;
}