#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        long long ans = 0, n, m;
        cin >> n >> m;
        if (n >= 0) {
            ans = (m * (m + 1)) / 2 - (n * (n + 1)) / 2 + n;
        }
        else if (n < 0) {
            n = abs(n);
            if (m >= 0) {
                ans = (m * (m + 1)) / 2 - (n * (n + 1)) / 2;
            }
            else if (m < 0) {
                m = abs(m);
                ans = -(m * (m + 1)) / 2 + (n * (n + 1)) / 2 + m;
                ans *= (-1);
            }
        }
        cout << "Scenario #" << i << ":\n" << ans << "\n\n";
    }
    return 0;
}