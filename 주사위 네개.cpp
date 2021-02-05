#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, ans = 0; 
    cin >> n;
    while (n--) {
        map<int, int> M;
        int temp = 0, cnt = 0, mx = 0;
        for (int i = 0; i < 4; i++) {
            int t; 
            cin >> t;
            M[t]++;
            mx = max(mx, t);
        }
        for (auto [key, val] : M) {
            cnt += val == 2;
        }
        for (auto [key, val] : M) {
            if (val == 4) {
                temp += 50000 + 5000 * key;
            }
            else if (val == 3) {
                temp += 10000 + 1000 * key;
            }
            else if (val == 2) {
                temp += (cnt == 2 ? 500 : 100) * key;
            }
        }
        if (cnt == 2) {
            temp += 2000;
        }
        else if (cnt == 1) {
            temp += 1000;
        }
        else if (M.size() == 4) {
            temp += mx * 100;
        }
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}