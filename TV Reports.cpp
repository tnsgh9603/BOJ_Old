#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cur, mx; 
    cin >> n >> cur >> mx;
    while (n--) {
        int t; 
        cin >> t;
        if (cur > t) {
            cout << "NTV: Dollar dropped by " << cur - t << " Oshloobs\n";
        }
        if (mx < t) {
            cout << "BBTV: Dollar reached " << t << " Oshloobs, A record!\n";
        }
        cur = t;
        mx = max(mx, t);
    }
    return 0;
}