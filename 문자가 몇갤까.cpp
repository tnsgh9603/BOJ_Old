#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (getline(cin, s) && s != "#") {
        bitset<26> v;
        for (auto i : s) {
            if ('a' <= i && i <= 'z') {
                v[i - 'a'] = 1;
            }
            if ('A' <= i && i <= 'Z') {
                v[i - 'A'] = 1;
            }
        }
        cout << v.count() << '\n';
    }
    return 0;
}
