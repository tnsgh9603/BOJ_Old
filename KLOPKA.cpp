#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
    fastio;
    int n;
    cin >> n;
    int mx1 = -INF, mx2 = -INF, mn1 = INF, mn2 = INF;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mx1 = max(mx1, a);
        mx2 = max(mx2, b);
        mn1 = min(mn1, a);
        mn2 = min(mn2, b);
    }
    int t = max(mx1 - mn1, mx2 - mn2);
    cout << t * t;
    return 0;
}