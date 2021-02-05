#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    double x, y;
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << fixed << setprecision(12) << 60 * (x - 1) / y << " " << 60 * x / y << " " << 60 * (x + 1) / y << "\n";
    }
    return 0;
}