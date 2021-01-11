#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!a && !b && !c && !d) {
            break;
        }
        int ans = 0;
        while (1) {
            int x, y, n, m;
            x = abs(a - b);
            y = abs(b - c);
            n = abs(c - d);
            m = abs(d - a);
            ans++;
            if (x == y && y == n && n == m) {
                break;
            }
            a = x, b = y, c = n, d = m;
        }
        if (a == b && b == c && c == d) {
            cout << 0 << '\n';
        }
        else
            cout << ans << '\n';
    }
    return 0;
}
