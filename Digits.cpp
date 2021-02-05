#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s, t;
    while (cin >> s && s != "END") {
        int cnt = 0;
        t = s;
        while (1) {
            cnt++;
            s = to_string(s.size());
            if (s == t) {
                break;
            }
            t = s;
        }
        cout << cnt << '\n';
    }
    return 0;
}