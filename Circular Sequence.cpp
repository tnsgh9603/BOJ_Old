#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    while (n--) {
        string s
            ; cin >> s;
        string mn = s;
        for (int i = 0; i < s.size(); i++) {
            s.push_back(s.front());
            s.erase(0, 1);
            mn = min(mn, s);
        }
        cout << mn << '\n';
    }
    return 0;
}