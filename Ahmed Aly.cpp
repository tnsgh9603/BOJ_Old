#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int a, b, c;
        char x, y;
        cin >> a >> x >> b >> y >> c;
        if (x == '+') {
            if (a + b == c) {
                cout << "Case " << i << ": YES\n";
            }
            else {
                cout << "Case " << i << ": NO\n";
            }
        }
        else if (x == '-') {
            if (a - b == c) {
                cout << "Case " << i << ": YES\n";
            }
            else {
                cout << "Case " << i << ": NO\n";
            }
        }
    }
    return 0;
}