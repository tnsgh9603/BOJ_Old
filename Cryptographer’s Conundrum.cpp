#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
char arr[5] = "PER";
int main() {
    fastio;
    int ans = 0;
    string s;
    cin >> s;
    for (int i = 0; s[i]; i++) {
        if (s[i] != arr[i % 3]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}