#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MOD = int(1e9) + 7;
int f[100001]{ 1 };
int main() {
    fastio;
    for (int i = 1; i <= 100000; i++) {
        f[i] = 1LL * f[i - 1] * i % MOD;
    }
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        cout << f[t] - 1 << '\n';
    }
    return 0;
}