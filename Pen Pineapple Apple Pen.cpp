#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 4) == "pPAp") {
            cnt++;
            i += 3;
        }
    }
    cout << cnt;
    return 0;
}