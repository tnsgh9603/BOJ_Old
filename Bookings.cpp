#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    int n;
    while (cin >> s >> n && s != "#") {
        char c;
        int x;
        while (cin >> c >> x && c != 'X') {
            if (c == 'B' && n + x <= 68) {
                n += x;
            }
            if (c == 'C' && n - x >= 0) {
                n -= x;
            }
        }
        cout << s << ' ' << n << '\n';
    }
    return 0;
}