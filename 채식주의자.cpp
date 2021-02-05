#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    double x, y; cin >> x >> y;
    double p = 250 * 250 / 2;
    cout << fixed << setprecision(2);
    if (!x) {
        if (y < 125) cout << p / (250 - y) << ' ' << 250 - p / (250 - y) << '\n';
        else cout << p / y << ' ' << 0. << '\n';
    }
    else if (!y) {
        if (x < 125) cout << 250 - p / (250 - x) << ' ' << p / (250 - x) << '\n';
        else cout << 0. << ' ' << p / x << '\n';
    }
    else {
        if (x > 125) cout << 0. << ' ' << 250 - p / x << '\n';
        else cout << 250 - p / y << ' ' << 0. << '\n';
    }
}