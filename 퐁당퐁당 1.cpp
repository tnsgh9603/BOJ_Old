#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
	int N, T, cnt = 0, ad = 1;
	cin >> N >> T;
	for (int i = 0; i < T; ++i) {
		cnt += ad;
		if (cnt == 1) {
			ad = 1;
		}
		if (cnt == 2 * N) {
			ad = -1;
		}
	}
	cout << cnt << "\n";
	return 0;
}