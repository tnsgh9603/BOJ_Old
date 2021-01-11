#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double ans, x, y;
    int i, n;
    cin >> x >> y >> n;
    ans = x / y * 1000;
    for (i = 0; i < n; i++) {
        double xx, yy;
        cin >> xx >> yy;
        if (ans >= (xx / yy) * 1000) { 
            ans = xx / yy * 1000;
        }
    }
    cout << fixed << setprecision(2) << ans << '\n';
    return 0;
}
