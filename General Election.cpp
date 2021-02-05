#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int s[11];
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            s[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                s[j + 1] += x;
            }
        }
        int mi = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] > s[mi]) {
                mi = i;
            }
        }
        cout << mi << "\n";
    }
    return 0;
}