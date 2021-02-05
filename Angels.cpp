#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int t, a, b, c;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << a << " " << b << " " << c;
        if (a + b + c == 180) {
            cout << " Seems OK\n";
        }
        else {
            cout << " Check\n";
        }
    }
    return 0;
}