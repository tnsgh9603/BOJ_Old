#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
const ll MOD = 16769023;

ll _pow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int main() {
    fastio;
    ll n; cin >> n;
    cout << _pow(2, n + 1 >> 1) << '\n';
}