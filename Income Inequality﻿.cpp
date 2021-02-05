#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int avg = accumulate(v.begin(), v.end(), 0) / n;
        cout << accumulate(v.begin(), v.end(), 0, [&](int ret, int _val) {
            return _val <= avg ? ret + 1 : ret;
            }) << '\n';
    }
    return 0;
}