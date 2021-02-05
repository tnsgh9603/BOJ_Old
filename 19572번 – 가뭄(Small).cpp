#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a, b, c;
    cin >> a >> b >> c;
    double d = (a + b + c) / 2;
    if (d <= a || d <= b || d <= c) {
        cout << -1;
        return 0;
    }
    double e, f, g;
    e = d - c;
    f = d - b;
    g = d - a;
    e = round(e * 10) / 10;
    f = round(f * 10) / 10;
    g = round(g * 10) / 10;
    cout << fixed << setprecision(1) << 1 << '\n' << e << ' ' << f << ' ' << g;
    return 0;
}