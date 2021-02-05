#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    int a, b, c, cnt = 0;
    while (cin >> a && a) {
        cin >> b >> c;
        cout << "Pizza " << ++cnt << ' ' << (4 * a * a >= b * b + c * c ? "fits" : "does not fit") << " on the table." << '\n';
    }
    return 0;
}
