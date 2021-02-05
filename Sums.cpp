#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int S[3][10000], n[10000];
int main() {
	fastio;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n[i];
		for (int j = 1; j <= n[i]; j++) {
			S[0][i] += j;
			S[1][i] += 2 * j - 1;
			S[2][i] += 2 * j;
		}
	}
	for (int i = 0; i < t; i++) {
		cout << S[0][i] << " " << S[1][i] << " " << S[2][i] << '\n';
	}
	return 0;
}