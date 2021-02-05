#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int main() {
    fastio;
    double a, b;
    cin >> a >> b;
    double plus = -a + sqrt(a * a - b);
    double minus = -a - sqrt(a * a - b);
    if (plus == minus) {
        cout << plus << '\n';
    }
    else {
        cout << minus << " " << plus << '\n';
    }
    return 0;
}