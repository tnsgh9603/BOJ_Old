#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    while (getline(cin, s) && s != "#") {
        int t = 'A' - s.back() + 26;
        for (auto& i : s) {
            if (!isalpha(i)) {
                continue;
            }
            if (i < 'a') {
                i = (i - 'A' + t) % 26 + 'A';
            }
            else {
                i = (i - 'a' + t) % 26 + 'a';
            }
        }
        s.pop_back();
        cout << s << '\n';
    }
    return 0;
}