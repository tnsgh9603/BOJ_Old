#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    cin >> s;
    vector<char> v;
    v.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] == '-') {
            v.push_back(s[i]);
        }
    }
    for (auto i : v) {
        cout << i;
    }
    return 0;
}
