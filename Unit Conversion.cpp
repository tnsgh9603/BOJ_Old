#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << fixed << setprecision(6);
    while (n--) {
        double t;
        char c;
        cin >> t >> c;
        if (c == 'A') {
            cout << t / a * b << '\n';
        }
        else {
            cout << t / b * a << '\n';
        }
    }
    return 0;
}