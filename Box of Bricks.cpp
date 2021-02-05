#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    while (cin >> n && n) {
        cout << "Set #" << ++cnt << '\n';
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int avg = accumulate(v.begin(), v.end(), 0) / n;
        int ans = accumulate(v.begin(), v.end(), 0, [&](int ret, int _val) {
            return _val < avg ? ret + avg - _val : ret;
            });
        cout << "The minimum number of moves is " << ans << ".\n\n";
    }
    return 0;
}