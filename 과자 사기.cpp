#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double sp, sw, np, nw, up, uw;
    cin >> sp >> sw >> np >> nw >> up >> uw;
    sp *= 10;
    np *= 10; 
    up *= 10;
    sw *= 10;
    nw *= 10; 
    uw *= 10;
    if (sp >= 5000) {
        sp -= 500;
    }
    if (np >= 5000) {
        np -= 500;
    }
    if (up >= 5000) {
        up -= 500;
    }
    pair <double, char> S = { sp / sw, 'S' };
    pair <double, char> N = { np / nw, 'N' };
    pair <double, char> U = { up / uw, 'U' };
    pair <double, char> result = min({ S, N, U });
    cout << result.second;
    return 0;
}