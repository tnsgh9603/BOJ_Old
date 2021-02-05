#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    vector<int> v(26);
    string s; getline(cin, s);
    for (auto i : s) {
        if (!isalpha(i)) {
            continue;
        }
        v[tolower(i) - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << " | " << string(v[i], '*') << '\n';
    }
    return 0;
}