#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        long long a;
        cin >> a;
        bool flag = true;
        while (1) {
            if (a == 1) {
                break;
            }
            if (a % 2 == 0) {
                a /= 2;
            }
            else {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}