#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t, n, k, candy, ans;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> k;
        while (n--) {
            cin >> candy;
            ans += candy / k;
        }
        cout << ans << '\n';
    }
    return 0;
}