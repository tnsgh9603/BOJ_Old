#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    int n; cin >> n;
    string s, t = to_string(n);
    for (int i = 1; i <= n; i++) {
        s += to_string(i);
    }
    for (int i = 0; i < (int)s.size() - (int)t.size() + 1; i++) {
        if (s.substr(i, t.size()) == t) {
            cout << i + 1 << '\n';
            return 0;
        }
    }
}
