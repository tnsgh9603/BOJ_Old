#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    while (cin >> n && n) {
        cin.ignore();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);
            if (s.size() < mx) {
                continue;
            }
            for (int j = mx; j < s.size() && s[j] != ' '; j++, mx++);
        }
        cout << mx + 1 << '\n';
    }
    return 0;
}