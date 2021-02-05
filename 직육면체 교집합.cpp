#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, x1, y1, z1, x2, y2, z2;
    x1 = y1 = z1 = -1e9; x2 = y2 = z2 = 1e9;
    cin >> n;
    while (n--) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        x1 = max(x1, a);
        y1 = max(y1, b);
        z1 = max(z1, c);
        x2 = min(x2, d);
        y2 = min(y2, e);
        z2 = min(z2, f);
    }
    if (x1 > x2 || y1 > y2 || z1 > z2) {
        cout << 0;
    }
    else {
        cout << (x2 - x1) * (y2 - y1) * (z2 - z1);
    }
    return 0;
}