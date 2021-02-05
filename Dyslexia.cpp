#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n; 
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            ans++;
        }
    }
    cout << n - ans;
    return 0;
}
