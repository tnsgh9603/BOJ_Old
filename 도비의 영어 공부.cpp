#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (getline(cin, s) && s != "#") {
        for (auto& i : s) {
            i = tolower(i);
        }
        cout << s[0] << ' ' << count(s.begin(), s.end(), s[0]) - 1 << '\n';
    }
    return 0;
}
