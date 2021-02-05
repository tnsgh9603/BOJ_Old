#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s, ans;
    cin >> s;
    for (int i = s.size() - 1, t = 1; i >= 0; i--, t++) {
        ans += s[i];
        if (t % 3 == 0) {
            ans += ',';
        }
    }
    if (ans.back() == ',') {
        ans.pop_back();
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}