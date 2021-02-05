#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, x, ans = 0;
    cin >> n;
    while (n--) {
        cin >> x;
        ans += (x == 2) || (x == 3);
    }
    cout << ans;
    return 0;
}