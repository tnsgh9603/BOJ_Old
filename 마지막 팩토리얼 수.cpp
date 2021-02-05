#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

int main() {
    fastio;
    vector<ll> v(20001);
    v[0] = v[1] = 1;
    for (int i = 2; i <= 20000; i++) {
        v[i] = v[i - 1] * i;
        while (v[i] % 10 == 0) v[i] /= 10;
        v[i] %= ll(1e9);
    }
    int n; cin >> n;
    cout << v[n] % 10 << '\n';
}