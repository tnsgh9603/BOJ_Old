#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, s, mx = 0; 
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        mx = max(mx, t);
    }
    cout << (1LL * mx * s + 999) / 1000 << '\n';
    return 0;
}