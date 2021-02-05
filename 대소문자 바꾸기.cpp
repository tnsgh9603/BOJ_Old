#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    string s; 
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cout << ' ';
            continue;
        }
        if (s[i] < 91) {
            cout << char(s[i] + 32);
        }
        else {
            cout << char(s[i] - 32);
        }
    }
    return 0;
}
