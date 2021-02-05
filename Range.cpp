#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a, b;
    while (cin >> a >> b && a != -1) {
        double pa = a, pb = b;
        double t1 = 0, t2 = 0;
        while (cin >> a >> b) {
            if (!a && !b) {
                break;
            }
            if (b < pb) {
                t1 += a - pa;
                t2 += pb - b;
            }
            pa = a, pb = b;
        }
        cout << round(t1 * pb / t2) << '\n';
    }
    return 0;
}