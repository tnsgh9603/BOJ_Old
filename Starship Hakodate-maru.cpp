#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	while (1) {
		int N, ans = -1; 
		cin >> N;
		if (!N) {
			break;
		}
		for (int i = 0; i * i * i <= N; ++i) {
			for (int j = 0; (i * i * i) + (j * (j + 1) * (j + 2)) / 6 <= N; ++j) {
				if ((i * i * i) + (j * (j + 1) * (j + 2)) / 6 > ans) {
					ans = (i * i * i) + (j * (j + 1) * (j + 2)) / 6;
				}
			}
		} 
		cout << ans << "\n";
	}
	return 0;
}