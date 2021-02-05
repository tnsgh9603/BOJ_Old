#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s; 
        cin >> s;
        cout << (s[(s.size() >> 1) - 1] == s[s.size() >> 1] ? "Do-it" : "Do-it-Not") << '\n';
    }
    return 0;
}
