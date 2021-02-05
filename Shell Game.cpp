#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n, a[101], b[101], g[101];
int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i];
        a[i]--;
        b[i]--;
        g[i]--;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int shell[3] = {};
        int cnt = 0;
        shell[i] = 1;
        for (int j = 0; j < n; j++) {
            swap(shell[a[j]], shell[b[j]]);
            if (shell[g[j]]) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}