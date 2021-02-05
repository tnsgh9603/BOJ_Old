#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t, n, m, i;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> n >> m;
        cout << 2 * m - n << " " << m - (2 * m - n) << "\n";
    }
    return 0;
}