#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll _pow(ll r, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) {
            ret *= r;
        }
        r *= r;
        n >>= 1;
    }
    return ret;
}

int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a != b && a * c == b * b) {
            ll r = b / a;
            cout << a * (_pow(r, n) - 1) / (r - 1) << '\n';
        }
        else {
            cout << n * (2 * a + (n - 1) * (b - a)) / 2 << '\n';
        }
    }
    return 0;
}