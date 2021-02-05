#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    vector<int> v(n + 1), w(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a] = b;
        w[a] = c;
    }
    int ans = 0, i = 1;
    while (i != n) {
        if (w[i]) {
            ans ^= w[i];
        }
        i = v[i];
    }
    cout << ans << '\n';
    return 0;
}