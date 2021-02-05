#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
pair<string, int> d[11];
int n, ans;
bool chk(int x) {
    for (int i = 0; i < n; i++) {
        if (d[i].first == "ADD") {
            x += d[i].second;
        }
        if (d[i].first == "SUBTRACT") {
            x -= d[i].second;
            if (x < 0) {
                return 0;
            }
        }
        if (d[i].first == "MULTIPLY") {
            x *= d[i].second;
        }
        if (d[i].first == "DIVIDE") {
            if (x % d[i].second != 0) {
                return 0;
            }
            x /= d[i].second;
        }
    }
    return 1;
}
int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i].first >> d[i].second;
    }
    for (int i = 1; i <= 100; i++) {
        if (!chk(i)) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}