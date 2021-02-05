#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s; 
    cin >> s;
    bool flag = 1;
    for (int i = 0, sz = s.size(); i < sz >> 1 && flag; i++) {
        if (s[i] != s[sz - 1 - i]) {
            flag = 0;
        }
    }
    cout << boolalpha << flag;
    return 0;
}