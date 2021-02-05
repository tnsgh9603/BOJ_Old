#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int ans = 0, n;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100 - i; j++) {
            for (int k = 1; k <= 100 - i - j; k++) {
                if (i >= j + 2 && j != 0 && k != 0 && k % 2 == 0 && i + j + k == n) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}