#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    string s; 
    cin >> s;
    int ans = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            ans *= (s[i] == 'c' ? 26 : 10);
        }
        else {
            ans *= (s[i] == 'c' ? 25 : 9);
        }
    }
    cout << ans;
    return 0;
}
