#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n; i++) {
        for (int _ = 0; _ < a; _++) {
            for (int j = 0; j < m; j++) {
                cout << string(b, (i + j) & 1 ? '.' : 'X');
            }
            cout << '\n';
        }
    }
    return 0;
}
