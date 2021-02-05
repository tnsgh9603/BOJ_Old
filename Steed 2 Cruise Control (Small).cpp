#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        cout << "Case #" << j << ":";
        int d, n;
        cin >> d >> n;
        double ans = 2147483647.0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            ans = min(ans, (double)y * d / (d - x));
        }
        cout << fixed << setprecision(12) << ans << "\n";
    }
    return 0;
}