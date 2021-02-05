#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        for (auto& i : s) {
            i = tolower(i);
        }
        for (int i = 0, sz = s.size() >> 1; i < sz; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                cout << "No" << '\n';
                goto Flag;
            }
        }
        cout << "Yes" << '\n';
    Flag:;
    }
    return 0;
}