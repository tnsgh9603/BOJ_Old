#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int x[401], y[401], r[401];
int main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) < (r[i] + r[j]) * (r[i] + r[j])) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}