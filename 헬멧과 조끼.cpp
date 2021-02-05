#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int m, n, a = 0, b = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int h;
        cin >> h;
        a = max(a, h);
    }
    for (int j = 0; j < n; j++) {
        int p;
        cin >> p;
        b = max(b, p);
    }
    cout << a + b;
    return 0;
}