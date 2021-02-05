#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define EPS 1e-5
using namespace std;
int main() {
    fastio;
    int a, b, c, p, q, r;
    cin >> a >> b >> c;
    p = a;
    q = 2 * b * c;
    r = a * (c * c - a * a + b * b);
    int d = q * q - 4 * p * r;
    if (d < 0) {
        cout << -1;
        return 0;
    }
    double x;
    x = (-q + sqrt(d)) / (2 * p);
    if (x < 0) {
        cout << -1;
        return 0;
    }
    cout << (int)(x + EPS);
}