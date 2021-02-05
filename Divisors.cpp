#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int arr[1006001];
int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        int ans = 0, n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans++;
            }
        }
        cout << n << " " << ans << '\n';
    }
    return 0;
}