#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        long long a, b, ans = 0;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        for (int i = 0; a > 0 || b > 0; a /= 10, b /= 10) {
            long long x = a % 10, y = b % 10;
            if (x + y + i > 9) {
                ans++;
                i = 1;
            }
            else {
                i = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}