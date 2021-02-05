#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << accumulate(v.begin(), v.end(), 0) / 10 << '\n';
    int cnt = 0, ans;
    for (int i = 0; i < 10;) {
        int temp = upper_bound(v.begin(), v.end(), v[i]) - lower_bound(v.begin(), v.end(), v[i]);
        if (temp > cnt) {
            cnt = temp, ans = v[i];
        }
        i += temp;
    }
    cout << ans << '\n';
    return 0;
}