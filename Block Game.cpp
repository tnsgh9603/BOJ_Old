#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int ans[201], tmp1[201], tmp2[201];
int main() {
    fastio;
    int N;
    cin >> N;
    while (N--) {
        memset(tmp1, 0, sizeof(tmp1));
        memset(tmp2, 0, sizeof(tmp2));
        string s, t;
        cin >> s >> t;
        for (int j = 0; j < s.size(); j++) {
            tmp1[s[j]]++;
        }
        for (int j = 0; j < t.size(); j++) {
            tmp2[t[j]]++;
        }
        for (int j = 'a'; j <= 'z'; j++) {
            ans[j] += max(tmp1[j], tmp2[j]);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}