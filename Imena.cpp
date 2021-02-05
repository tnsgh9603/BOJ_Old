#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    cin >> n;
    string s;
    while (cin >> s) {
        bool flag = 1;
        for (auto i : s) {
            if (isdigit(i)) {
                flag = 0;
            }
        }
        if (flag && 'A' <= s[0] && s[0] <= 'Z') {
            cnt++;
        }
        if (string(".?!").find(s.back()) != -1) {
            cout << cnt << '\n', cnt = 0;
        }
    }
    return 0;
}