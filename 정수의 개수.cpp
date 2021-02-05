#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    string s; 
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            ans++;
        }
    }
    cout << ans + 1;
    return 0;
}
