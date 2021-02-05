#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[10];
int main() {
	fastio;
	long long a;
	while (cin >> a) {
		memset(arr, 0, sizeof(arr));
		int ans = 1;
		long long save2 = a;
		while (1) {
			long long save = a;
			if (a < 10) {
				arr[a] = 1;
			}
			while (a / 10 > 0) {
				arr[a % 10] = 1;
				a /= 10;
			}
			arr[a] = 1;
			a = save;
			int cnt = 0;
			for (int i = 0; i <= 9; i++) {
				if (arr[i]) {
					cnt++;
				}
			}
			if (cnt == 10) {
				break;
			}
			ans++;
			a += save2;
		}
		cout << ans << "\n";
	}
	return 0;
}