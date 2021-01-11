#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    int t, n;
    long long cnt, candy;
    cin >> t;
    while (t--) {
        cin >> n;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> candy;
            cnt += candy;
            cnt %= n;
        }
        if (cnt) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}
