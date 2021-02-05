#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int INF = int(1e9);
int main() {
    fastio;
    int n, mn = INF;
    cin >> n;
    for (int i = 1, sz = sqrt(n); i <= sz; i++) {
        for (int j = i; j <= sz; j++) {
            if (n % (i * j)) {
                continue;
            }
            int k = n / i / j;
            mn = min(mn, i * j + j * k + k * i);
        }
    }
    cout << 2 * mn;
    return 0;
}