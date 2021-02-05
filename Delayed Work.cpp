#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double K, P, X, temp, t, i = 1;
    cin >> K >> P >> X;
    temp = 2 * sqrt(K * P * X);
    t = 2 * X;
    while (t * i < temp) {
        i += 1;
    }
    cout << fixed << setprecision(3) << X * i + K * P / i;
    return 0;
}