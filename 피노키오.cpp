#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll MOD = ll(1e9) + 7;
int main() {
    fastio;
    vector<ll> v(4);
    ll n;
    string s;
    cin >> n >> s;
    for (auto i : s) {
        v[string("ATGC").find(i)]++;
    }
    cout << accumulate(v.begin(), v.end(), 1, [&](ll ret, ll _val) {
        return ret * _val % MOD;
        }) << '\n';
}