#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            ans += i;
        }
    }
    cout << ans * 5 - 24 << '\n';
    return 0;
}