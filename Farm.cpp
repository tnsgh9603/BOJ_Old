#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, n, w, S, G, s, g, cnt = 0;
    cin >> a >> b >> n >> w;
    for (S = 1; S < n; S++) {
        G = n - S;
        if ((a * S + b * G) == w) {
            cnt++;
            s = S;
            g = G;
        }
    }
    if (cnt == 1) {
        cout << s << " " << g;
    }
    else {
        cout << -1;
    }
    return 0;
}