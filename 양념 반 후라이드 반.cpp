#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long
int main() {
    fastio;
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll first = min(X, Y);
    ll ans = min(A * (X - first) + B * (Y - first), C * 2 * max(X - first, Y - first));
    if (A + B > C * 2) {
        ans += first * 2 * C;
    }
    else {
        ans += A * first + B * first;
    }
    cout << ans;
    return 0;
}