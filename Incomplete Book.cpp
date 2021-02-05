#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    fastio;
    ll n, m;
    cin >> n >> m;
    ll tmp = n, ans = 0;
    for (int i = 1;; i++) {
        if (ans + tmp > m) {
            return !printf("%d", i - 1);
        }
        ans += tmp;
        tmp *= 2;
    }
    return 0;
}