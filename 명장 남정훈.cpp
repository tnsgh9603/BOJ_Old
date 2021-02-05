#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int l, r, a;
    cin >> l >> r >> a;
    int diff = abs(l - r);
    if (diff == 0) cout << 2 * (l + a / 2) << '\n';
    else {
        if (diff >= a) cout << 2 * (min(l, r) + a) << '\n';
        else {
            a -= diff;
            cout << 2 * (max(l, r) + a / 2) << '\n';
        }
    }
    return 0;
}