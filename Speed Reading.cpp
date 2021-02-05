#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, q; 
    cin >> n >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0, temp = n;
        while (temp > 0) {
            if (temp - a * b > 0) {
                temp -= a * b;
                ans += b + c;
            }
            else {
                ans += temp / a + bool(temp % a);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}