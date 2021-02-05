#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, cnt = 0;
    cin >> n;
    while (n--) {
        string s; cin >> s;
        regex r(".*?CD.*?");
        if (!regex_match(s, r)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}