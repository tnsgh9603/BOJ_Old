#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s;
    int h, m;
    cin >> s; s[2] = ' ';
    stringstream in(s);
    in >> h >> m;
    int n = h * 3600 + m * 60, cnt = 0;
    while (cnt != 7200) {
        cnt++;
        if (7 * 3600 <= n && n <= 10 * 3600 || 15 * 3600 <= n && n <= 19 * 3600) {
            n += 2;
        }
        else {
            n++;
        }
        n %= 3600 * 24;
    }
    cout << setfill('0') << setw(2) << n / 3600 << ':' << setfill('0') << setw(2) << n % 3600 / 60 << '\n';
    return 0;
}