#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == "ABC"[i % 3]) {
            a++;
        }
        if (s[i] == "BABC"[i % 4]) {
            b++;
        }
        if (s[i] == "CCAABB"[i % 6]) {
            c++;
        }
    }
    int mx = max({ a, b, c });
    cout << mx << '\n';
    if (a == mx) {
        cout << "Adrian" << '\n';
    }
    if (b == mx) {
        cout << "Bruno" << '\n';
    }
    if (c == mx) {
        cout << "Goran" << '\n';
    }
    return 0;
}