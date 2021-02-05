#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    auto f = [&](int n) {
        string s = to_string(n);
        int ret = 0;
        for (auto i : s) ret += i - '0';
        return ret;
    };
    while (cin >> n) {
        int ans = 0, t = f(n);
        if (!n) {
            break;
        }
        for (int i = 11; i <= 100 && !ans; i++) {
            if (!(t ^ f(n * i))) {
                ans = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}