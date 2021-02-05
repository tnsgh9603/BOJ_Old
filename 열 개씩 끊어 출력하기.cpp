#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        cout << s[i];
        if (i % 10 == 9) {
            cout << '\n';
        }
    }
    return 0;
}
