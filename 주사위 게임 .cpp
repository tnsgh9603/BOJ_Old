#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m; 
    cin >> n >> m;
    vector<int> v(n), w(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }
    int ans = 0, t = 1;
    while (t < n) {
        t += w[ans++];
        if (t >= n) {
            break;
        }
        t += v[t - 1];
    }
    cout << ans;
    return 0;
}