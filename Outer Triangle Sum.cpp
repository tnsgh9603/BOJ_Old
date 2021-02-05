#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    while (cin >> n && n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                int t;
                cin >> t;
                if (j == 1 || j == i || i == n) {
                    sum += t;
                }
            }
        }
        cout << "Case #" << ++cnt << ":" << sum << '\n';
    }
    return 0;
}