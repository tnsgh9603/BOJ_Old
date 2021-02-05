#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
bool f(string& s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] != ' ' && s[i] == s[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    fastio;
    string s;
    while (getline(cin, s) && s != "END") {
        if (f(s)) {
            cout << s << '\n';
        }
    }
    return 0;
}