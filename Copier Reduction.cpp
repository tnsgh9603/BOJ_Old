#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    while (1) {
        double temp, a, b, x, y;
        cin >> a >> b >> x >> y;
        if (!a && !b && !x && !y) {
            break;
        }
        if (b > a) {
            temp = a;
            a = b;
            b = temp;
        }
        if (y > x) {
            temp = x;
            x = y;
            y = temp;
        }
        // a>=b, x>=y
        double mx = max(a / x, b / y);
        if ((int)(100 * (1 / mx)) >= 100) {
            cout << "100%\n";
        }
        else {
            cout << (int)(100 * (1 / mx)) << "%\n";
        }
    }
    return 0;
}