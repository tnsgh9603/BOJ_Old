#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	long long T;
	cin >> T;
	while (T--) {
		long long N, arr[1001];
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i < N - 1; i++) {
			if (arr[i - 1] <= arr[i + 1] && (arr[i - 1] >= arr[i] || arr[i] >= arr[i + 1])) {
				cout << i + 1 << "\n";
			}
		}
	}
	return 0;
}