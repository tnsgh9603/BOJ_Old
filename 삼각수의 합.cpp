#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
	fastio;
    int T, n, sum;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> n;
        sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += (j + 1) * (j + 2) / 2 * j;
        }
        cout << sum << "\n";
    }
	return 0;
}