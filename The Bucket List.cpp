#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    fastio;
    int n, ans = 0;; cin >> n;
    vector<int> v(1001);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        for (int j = a; j <= b; j++) {
            v[j] += c;
            ans = max(ans, v[j]);
        }
    }
    cout << ans << '\n';
}