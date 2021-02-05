#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c;
    while (cin >> a >> b >> c && (a || b || c)) {
        int t = (a + b + c) % 25 + 1;
        cin.ignore();
        string s; 
        getline(cin, s);
        for (auto& i : s) {
            if (!isalpha(i)) {
                continue;
            }
            i = (i - t + 26 - 'a') % 26 + 'a';
        }
        cout << s << '\n';
    }
    return 0;
}