#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
set<ll> S;
int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] + v[j] == k) {
                S.insert(min<ll>(v[i], v[j] * ll(1e6) + max(v[i], v[j])));
            }
        }
    }
    cout << S.size();
    return 0;
}