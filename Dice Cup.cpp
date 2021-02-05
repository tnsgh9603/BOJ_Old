#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    while (cin >> n >> m) {
        vector<int> v(n + m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i + j]++;
            }
        }
        int mx = *max_element(v.begin(), v.end());
        for (int i = 0; i < n + m; i++) {
            if (v[i] == mx) {
                cout << i + 2 << '\n';
            }
        }
    }
    return 0;
}