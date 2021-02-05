#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, a, b; cin >> n >> a >> b;
    double r = hypot(a, b);
    while (n--) {
        int t; 
        cin >> t;
        cout << (t <= r ? "YES" : "NO") << '\n';
    }
    return 0;
}