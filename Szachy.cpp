#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, sum = 0; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        int mx = -int(1e9);
        for (int j = 0; j < n; j++) {
            int t; {
                cin >> t;
            }
            mx = max(mx, t);
        }
        sum += max(mx, 0);
    }
    cout << sum << '\n';
    return 0;
}