#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, f1, c, d, f2;
        cin >> a >> b >> f1 >> c >> d >> f2;
        cout << f1 + f2 + abs(a - c) + abs(b - d) << '\n';
    }
    return 0;
}