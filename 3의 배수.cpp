#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = 1; j <= n / 3; j++) {
            int sum = 0;
            sum = i * 3 + j * 3;
            if ((n - sum) % 3 == 0 && sum < n) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}