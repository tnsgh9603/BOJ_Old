#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b, c, v;
        cin >> a >> b >> c >> v;
        if (!a && !b && !c && !v) {
            break;
        }
        if (!a) {
            cout << v / (b * c) << " " << b << " " << c << " " << v << '\n';
        }
        else if (!b) {
            cout << a << " " << v / (a * c) << " " << c << " " << v << '\n';
        }
        else if (!c) {
            cout << a << " " << b << " " << v / (a * b) << " " << v << '\n';
        }
        else {
            cout << a << " " << b << " " << c << " " << a * b * c << '\n';
        }
    }
    return 0;
}