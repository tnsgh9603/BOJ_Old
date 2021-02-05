#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int window[2001][2001];
int main() {
    fastio;
    for (int t = 0; t < 3; t++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += 1000, b += 1000, c += 1000, d += 1000;
        for (int i = a; i < c; i++) {
            for (int j = b; j < d; j++) {
                if (t != 2) {
                    window[i][j] = 1;
                }
                else {
                    window[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 2001; i++) {
        for (int j = 0; j < 2001; j++) {
            ans += window[i][j];
        }
    }
    cout << ans;
    return 0;
}