#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1001], brr[501], crr[501];
int main() {
	fastio;
	int a, max = 0, cnt = 0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> brr[i] >> crr[i];
		for (int j = brr[i]; j < crr[i]; j++) {
			arr[j]++;
		}
	}
	for (int i = 0; i < a; i++) {
		cnt = 0;
		for (int j = brr[i]; j < crr[i]; j++) {
			arr[j]--;
		}
		for (int k = 0; k < 1005; k++) {
			if (arr[k] > 0) {
				cnt++;
			}
		}
		if (cnt > max) {
			max = cnt;
		}
		for (int p = brr[i]; p < crr[i]; p++) {
			arr[p]++;
		}
	}
	cout << max;
	return 0;
}