#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int start, ans;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int p = s[i] - 'A';
        if (abs(start - p) < 13) {
            ans += abs(start - p);
        }
        else {
            ans += 26 - abs(start - p);
        }
        start = p;
    }
    cout << ans;
    return 0;
}