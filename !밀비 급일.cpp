#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    string s;
    while (1) {
        getline(cin, s);
        if (s == "END") {
            break;
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}
