#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    int n;
    cin >> s >> n;
    int ans = 0;
    for (auto i : s) {
        ans *= n;
        ans += ('0' <= i && i <= '9' ? i - '0' : i - 'A' + 10);
    }
    cout << ans;
    return 0;
}