#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s; 
    cin >> s;
    auto f = [](string s) {
        for (int i = 0, sz = s.size(); i < sz >> 1; i++) {
            if (s[i] != s[sz - 1 - i]) {
                return 0;
            }
        }
        return 1;
    };
    for (int i = 0; i < s.size(); i++) {
        for (int j = 2; j <= s.size() - i; j += 2) {
            if (f(s.substr(i, j))) {
                cout << "Or not.";
                return 0;
            }
        }
    }
    cout << "Odd.";
    return 0;
}