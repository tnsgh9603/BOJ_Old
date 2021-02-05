#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) {
            break;
        }
        if ((c - a) % b == 0 && (c - a) / b >= 0) {
            cout << abs((c - a) / b) + 1 << "\n";
        }
        else {
            cout << "X\n";
        }
    }
    return 0;
}