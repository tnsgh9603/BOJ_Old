#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    int ans = 0, r = 1;
    while (n % 2 == 1 && m % 2 == 1) {
        ans += r;
        n /= 2;
        m /= 2;
        r *= 4;
    }
    cout << ans;
    return 0;
}

