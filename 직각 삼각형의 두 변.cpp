#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    double a, b, c;
    int i = 1;
    while (1) {
        double ans = 0;
        cin >> a >> b >> c;
        if (!a && !b && !c) {
            break;
        }
        cout << "Triangle #" << i << '\n';
        i++;
        if (a == -1) {
            ans = sqrt(c * c - b * b);
            if (ans > 0) {
                cout << "a = " << fixed << setprecision(3) << ans << "\n";
            }
            else {
                cout << "Impossible.\n";
            }
        }
        else if (b == -1) {
            ans = sqrt(c * c - a * a);
            if (ans > 0) {
                cout << "b = " << fixed << setprecision(3) << ans << "\n";
            }
            else {
                cout << "Impossible.\n";
            }
        }
        else {
            ans = sqrt(a * a + b * b);
            if (ans > 0) {
                cout << "c = " << fixed << setprecision(3) << ans << "\n";
            }
            else {
                cout << "Impossible.\n";
            }
        }
        cout << '\n';
    }
    return 0;
}