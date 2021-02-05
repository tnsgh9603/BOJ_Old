#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int n, c, t;
    cin >> t;
    while (t--) {
        cin >> n >> c;
        if (n % c == 0) {
            cout << n / c << '\n';
        }
        else {
            cout << n / c + 1 << '\n';
        }
    }
    return 0;
}