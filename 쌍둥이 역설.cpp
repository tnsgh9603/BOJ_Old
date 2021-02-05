#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int main() {
    fastio;
    double a, b;
    cout << fixed << setprecision(3);
    while (cin >> a >> b) {
        if (!a && !b) {
            break;
        }
        cout << sqrt(1 - (b / a) * (b / a)) << '\n';
    }
    return 0;
}