#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    long long n;
    cin >> n;
    if (!n) {
        cout << 1;
        return 0;
    }
    if (n < 0) {
        cout << 32;
        return 0;
    }
    long long ans = 0;
    while ((1LL << ans) < n) {
        ans++;
    }
    cout << ans;
    return 0;
}
