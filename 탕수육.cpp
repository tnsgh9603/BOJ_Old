#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        string s, a, b;
        cin >> s;
        bitset<26> v;
        for (int i = 0; ; i += 2, i %= s.size()) {
            if (v[i]) {
                break;
            }
            v[i] = 1;
            a.push_back(s[i]);
        }
        v.reset();
        for (int i = 1 % s.size(); ; i += 2, i %= s.size()) {
            if (v[i]) {
                break;
            }
            v[i] = 1;
            b.push_back(s[i]);
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}