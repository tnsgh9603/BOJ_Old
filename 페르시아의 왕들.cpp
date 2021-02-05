#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (!a && !b && !c && !d) {
            break;
        }
        cout << c - b << " " << d - a << '\n';
    }
    return 0;
}