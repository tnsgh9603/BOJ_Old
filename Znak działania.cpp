#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
string f(int n) {
    if (n < 0) {
        return '(' + to_string(n) + ')';
    }
    else {
        return to_string(n);
    }
}
int main() {
    fastio;
    int a, b;
    cin >> a >> b;
    if (!b || a + b == a * b || a - b == a * b) {
        cout << "NIE" << '\n';
    }
    else {
        int mx = max({ a + b, a - b, a * b });
        if (mx == a + b) {
            cout << f(a) << '+' << f(b) << '=' << f(a + b) << '\n';
        }
        if (mx == a - b) {
            cout << f(a) << '-' << f(b) << '=' << f(a - b) << '\n';
        }
        if (mx == a * b) {
            cout << f(a) << '*' << f(b) << '=' << f(a * b) << '\n';
        }
    }
    return 0;
}