#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int a[101];
int main() {
    fastio;
    int n, m, x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> x;
        --x;
        if (a[x] != 2019 && a[x] + 1 != a[x + 1]) {
            ++a[x];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << "\n";
    }
    return 0;
}
