#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    fastio;
    vector<ll> v;
    for (ll i = 1; i * i * i <= 2'000'000'000; i++) {
        v.push_back(i * i * i);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << lower_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a) << '\n';
    }
    return 0;
}