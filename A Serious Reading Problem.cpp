#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
ll _pow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) {
            ret *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ret;
}

int main() {
    ll a, b, c, d;
    while (cin >> a >> b >> c >> d && (a || b || c || d)) {
        cout << _pow(a, b * c * d) << '\n';
    }
    return 0;
}