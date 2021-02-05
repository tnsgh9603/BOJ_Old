#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    fastio;
    string s;
    while (cin >> s && s != "0") {
        ll ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (s[i] - '0') * ((1LL << s.size() - i) - 1);
        }
        cout << ans << '\n';
    }
    return 0;
}