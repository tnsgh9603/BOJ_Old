#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (cin >> s) {
        int mx = 1;
        for (int i = 1, px = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[px]) {
                mx = max(mx, i - px);
                px = i;
            }
        }
        cout << mx << '\n';
    }
    return 0;
}
