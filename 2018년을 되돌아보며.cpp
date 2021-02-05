#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    cin >> s;
    regex r1("[2018]+");
    if (!regex_match(s, r1)) {
        cout << 0 << '\n';
        return 0;
    }
    for (auto i : string("2018")) {
        if (s.find(i) == -1) {
            cout << 1 << '\n';
            return 0;
        }
    }
    int cnt = count(s.begin(), s.end(), '2');
    for (auto i : string("018")) {
        if (count(s.begin(), s.end(), i) != cnt) {
            cout << 2 << '\n';
            return 0;
        }
    }
    cout << 8 << '\n';
    return 0;
}