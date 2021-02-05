#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        int idx, n; 
        cin >> idx >> n;
        cout << idx << " " << (n * (n + 1)) / 2 << " ";
        int j = 0, h = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (i % 2 == 0) {
                j += i;
            }
            else {
                h += i;
            }
        }
        cout << h << " " << j << '\n';
    }
    return 0;
}