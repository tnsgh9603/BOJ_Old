#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        if (d > 7 || !((a <= 56 && b <= 45 && c <= 25) || (a + b + c <= 125))) {
            cout << 0 << '\n';
        }
        else {
            cnt++, cout << 1 << '\n';
        }
    }
    cout << cnt << '\n';
    return 0;
}