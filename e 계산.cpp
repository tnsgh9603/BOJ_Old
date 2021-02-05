#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double t = 0;
    auto f = [&](int n) {
        double ret = 1;
        for (int i = 2; i <= n; i++) {
            ret *= i;
        }
        return ret;
    };
    cout << "n e\n- " << string(11, '-') << '\n';
    cout << "0 1" << '\n';
    cout << "1 2" << '\n';
    cout << "2 2.5" << '\n';
    cout << fixed << setprecision(9);
    for (int i = 0; i <= 9; i++) {
        t += 1 / f(i);
        if (i > 2) {
            cout << i << ' ' << t << '\n';
        }
    }
    return 0;
}