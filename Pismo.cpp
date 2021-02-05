#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, d[101010], ans = 2e9;
int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        if (i >= 2) {
            ans = min(ans, abs(d[i] - d[i - 1]));
        }
    }
    cout << ans;
    return 0;
}