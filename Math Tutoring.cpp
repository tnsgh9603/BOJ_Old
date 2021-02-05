#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t, n, m;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        cout << "Case " << i << ": " << n - 1;
        for (int j = n; j >= 0; j--) {
            cin >> m;
            if (j) {
                cout << " " << j * m;
            }
        }
        cout << "\n";
    }
    return 0;
}