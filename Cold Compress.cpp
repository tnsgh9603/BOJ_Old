#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        for (int i = 0, t = 1; i < s.size(); i++) {
            if (i != s.size() - 1 && s[i] == s[i + 1]) {
                t++;
            }
            else {
                cout << t << ' ' << s[i] << ' ', t = 1;
            }
        }
        cout << '\n';
    }
    return 0;
}