#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, ans;
    cin >> n;
    while (n != 0) {
        if (n == 1) {
            ans = 1;
        }
        else {
            ans = n * n;
            ans -= (n - 1);
        }
        cout << n << " => " << ans << "\n";
        cin >> n;
    }
    return 0;
}