#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c;
    while (cin >> a >> b >> c && (a || b || c)) {
        int half = a / 2 + 1;
        a -= b + c;
        if (b >= half) {
            cout << 0 << '\n';
        }
        else if (half - b > a) {
            cout << -1 << '\n';
        }
        else {
            cout << half - b << '\n';
        }
    }
    return 0;
}
