#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> cnt(101);
    int a, b, c, ans = 0;
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) {
        int d, e;
        cin >> d >> e;
        for (int j = d; j < e; j++) {
            cnt[j]++;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == 1) {
            ans += a * 1;
        }
        if (cnt[i] == 2) {
            ans += b * 2;
        }
        if (cnt[i] == 3) {
            ans += c * 3;
        }
    }
    cout << ans;
    return 0;
}
