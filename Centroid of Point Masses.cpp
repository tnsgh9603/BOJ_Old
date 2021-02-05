#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    while (cin >> n && n > 0) {
        cout << "Case " << ++cnt << ": ";
        double x, y, sum = 0; x = y = 0;
        for (int i = 0; i < n; i++) {
            double a, b, c; cin >> a >> b >> c;
            x += a * c, y += b * c;
            sum += c;
        }
        cout << fixed << setprecision(2) << x / sum << ' ' << y / sum << '\n';
    }
    return 0;
}